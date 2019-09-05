#include <stdlib.h>

#include <minitotp.h>

#include "test_common.h"

static const char secret[] = "12345678901234567890";

#define rfc6238_tabletest(time, result)                                        \
  do {                                                                         \
    char *otp = mtotp_totp(secret, time, 30, 8);                               \
    TEST_ASSERT_STREQ("time = " S(time), otp, result);                         \
    free(otp);                                                                 \
  } while (0)

TEST_MAIN_BEGIN()
// only HMAC-SHA-1
rfc6238_tabletest(59, "94287082");
rfc6238_tabletest(1111111109, "07081804");
rfc6238_tabletest(1111111111, "14050471");
rfc6238_tabletest(1234567890, "89005924");
rfc6238_tabletest(2000000000, "69279037");
rfc6238_tabletest(20000000000, "65353130");
TEST_MAIN_END()
