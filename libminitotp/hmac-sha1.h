#ifndef MINITOTP_HMAC_SHA1_H_
#define MINITOTP_HMAC_SHA1_H_

#include <stddef.h>
#include <stdint.h>

void hmac_sha1(const uint8_t *key, size_t key_len, const uint8_t *message,
               size_t message_len, uint8_t digest[20]);

#endif
