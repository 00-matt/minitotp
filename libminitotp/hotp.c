#include <minitotp.h>

#include <assert.h>
#include <endian.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/hmac.h>

static char *hmac(const char *key, size_t key_len, uint64_t counter) {
  // NOTE: Not thread safe
  return (char *)HMAC(EVP_sha1(), key, key_len, (unsigned char *)&counter,
                      sizeof(counter), NULL, 0);
}

static uint32_t dynamic_truncate(char *hmac) {
  int o = hmac[19] & 0x0F;

  return (hmac[o] & 0x7F) << 24 | (hmac[o + 1] & 0xff) << 16 |
         (hmac[o + 2] & 0xff) << 8 | (hmac[o + 3] & 0xff);
}

static uint32_t mpow10(uint32_t n) {
  int ret = 1;
  while (n--) {
    ret *= 10;
  }
  return ret;
}

static uint32_t mod(uint32_t truncated, int len) {
  return truncated % mpow10(len);
}

char *mtotp_hotp(const char *secret, uint64_t counter, int length) {
  assert(length >= 6);
  char *ret = calloc(length + 1, 1);
  if (!ret) {
    return NULL;
  }

  size_t secret_len = strlen(secret);
  counter = htobe64(counter);
  uint32_t code =
      mod(dynamic_truncate(hmac(secret, secret_len, counter)), length);

  snprintf(ret, length + 1, "%0*d", length, code);
  return ret;
}
