#include <stdlib.h>
#include <string.h>

#include "../hmac-sha1.h"
#include "test_common.h"

TEST_MAIN_BEGIN()
uint8_t digest[20];
hmac_sha1((const uint8_t *)"key", 3,
          (const uint8_t *)"The quick brown fox jumps over the lazy dog", 43,
          digest);
TEST_ASSERT("hmac-sha1 #0", memcmp(digest,
                                   "\xde\x7c\x9b\x85\xb8\xb7\x8a\xa6\xbc\x8a"
                                   "\x7a\x36\xf7\x0a\x90\x70\x1c\x9d\xb4\xd9",
                                   20) == 0);
TEST_MAIN_END()
