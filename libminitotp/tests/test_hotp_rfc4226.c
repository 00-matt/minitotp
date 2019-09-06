#include <stdlib.h>

#include <minitotp.h>

#include "test_common.h"

static const char secret[] = "12345678901234567890";

#define rfc4226_tabletest(count, result)                                       \
  do {                                                                         \
    char otp[7];                                                               \
    mtotp_hotp(secret, count, 6, otp);                                         \
    TEST_ASSERT_STREQ("count = " S(count), otp, result);                       \
  } while (0)

TEST_MAIN_BEGIN()
rfc4226_tabletest(0, "755224");
rfc4226_tabletest(1, "287082");
rfc4226_tabletest(2, "359152");
rfc4226_tabletest(3, "969429");
rfc4226_tabletest(4, "338314");
rfc4226_tabletest(5, "254676");
rfc4226_tabletest(6, "287922");
rfc4226_tabletest(7, "162583");
rfc4226_tabletest(8, "399871");
rfc4226_tabletest(9, "520489");
TEST_MAIN_END()
