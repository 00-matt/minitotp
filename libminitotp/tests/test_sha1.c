#include <stdlib.h>
#include <string.h>

#include "../sha1.h"
#include "test_common.h"

#define sha1_test(id, message, message_len, expected_digest)                   \
  do {                                                                         \
    uint8_t real_digest[20];                                                   \
    struct sha1_ctx ctx;                                                       \
    sha1_init(&ctx);                                                           \
    sha1_update(&ctx, message, message_len);                                   \
    sha1_finalise(&ctx, real_digest);                                          \
    TEST_ASSERT("sha1 #" S(id),                                                \
                memcmp(expected_digest, real_digest, 20) == 0);                \
  } while (0)

#define sha1_test_str(id, message, expected_digest)                            \
  sha1_test(id, (const uint8_t *)message, strlen(message), expected_digest)

TEST_MAIN_BEGIN()
sha1_test(0, NULL, 0,
          "\xda\x39\xa3\xee\x5e\x6b\x4b\x0d\x32\x55\xbf\xef\x95"
          "\x60\x18\x90\xaf\xd8\x07\x09");
sha1_test_str(1, "abc",
              "\xa9\x99\x3e\x36\x47\x06\x81\x6a\xba\x3e\x25\x71"
              "\x78\x50\xc2\x6c\x9c\xd0\xd8\x9d");
TEST_MAIN_END()
