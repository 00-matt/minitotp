#ifndef MINITOTP_SHA1_H_
#define MINITOTP_SHA1_H_

#include <stdint.h>

struct sha1_ctx {
  uint32_t state[5];
  uint32_t count[2];
  uint8_t buf[64];
};

void sha1_init(struct sha1_ctx *ctx);

void sha1_update(struct sha1_ctx *ctx, const uint8_t *input,
                 uint32_t input_len);

void sha1_finalise(struct sha1_ctx *ctx, uint8_t digest[20]);

#endif
