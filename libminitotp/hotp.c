#include <minitotp.h>

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "bits.h"
#include "hmac-sha1.h"
#include "pad-otp.h"

static uint32_t dynamic_truncate(uint8_t hmac[20]) {
  int o = hmac[19] & 0x0F;

  return ((uint32_t)(hmac[o] & 0x7F)) << 24 |
         ((uint32_t)(hmac[o + 1] & 0xff)) << 16 | (hmac[o + 2] & 0xff) << 8 |
         (hmac[o + 3] & 0xff);
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

char *mtotp_hotp_l(const char *secret, size_t secret_len, uint64_t counter,
                   int length, char *buf) {
  assert(secret_len > 0);
  assert(length >= 6);

  counter = htobe64(counter);
  uint8_t hmac[20];
  hmac_sha1((const uint8_t *)secret, secret_len, (const uint8_t *)&counter,
            sizeof(counter), hmac);

  uint32_t code = mod(dynamic_truncate(hmac), length);

  pad_otp(code, length, buf);

  return buf;
}

char *mtotp_hotp(const char *secret, uint64_t counter, int length, char *buf) {
  const size_t secret_len = strlen(secret);
  return mtotp_hotp_l(secret, secret_len, counter, length, buf);
}
