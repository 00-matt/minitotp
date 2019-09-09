#include "hmac-sha1.h"

#include <string.h>

#include "sha1.h"

static void fix_key(const uint8_t *key, size_t key_len, uint8_t fixed_key[64]) {
  memset(fixed_key, 0, 64);

  if (key_len > 64) {
    struct sha1_ctx ctx;
    sha1_init(&ctx);
    sha1_update(&ctx, (const uint8_t *)key, key_len);
    sha1_finalise(&ctx, fixed_key);
    return;
  }

  memcpy(fixed_key, key, key_len > 64 ? 64 : key_len);
}

#include <stdio.h>

void hmac_sha1(const uint8_t *key, size_t key_len, const uint8_t *message,
               size_t message_len, uint8_t digest[20]) {
  struct sha1_ctx ctx;
  uint8_t fixed_key[64];
  uint8_t inner_digest[20];
  uint8_t inner_pad[64];
  uint8_t outer_pad[64];

  memset(fixed_key, 0, 64);
  if (key_len > 64) {
    sha1_init(&ctx);
    sha1_update(&ctx, (const uint8_t *)key, key_len);
    sha1_finalise(&ctx, fixed_key);
  } else {
    memcpy(fixed_key, key, key_len > 64 ? 64 : key_len);
  }

  for (int i = 0; i < 64; i++) {
    inner_pad[i] = fixed_key[i] ^ 0x36;
    outer_pad[i] = fixed_key[i] ^ 0x5c;
  }

  // perform inner hash
  sha1_init(&ctx);
  sha1_update(&ctx, inner_pad, 64);
  sha1_update(&ctx, message, message_len);
  sha1_finalise(&ctx, inner_digest);

  sha1_init(&ctx);
  sha1_update(&ctx, outer_pad, 64);
  sha1_update(&ctx, inner_digest, 20);
  sha1_finalise(&ctx, digest);
}
