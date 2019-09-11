#include "../pad-otp.h"
#include "test_common.h"

TEST_MAIN_BEGIN()
char buf[10];

pad_otp(123456, 6, buf);
TEST_ASSERT_STREQ("123456", buf, "123456");

pad_otp(12345, 6, buf);
TEST_ASSERT_STREQ("012345", buf, "012345");

pad_otp(0, 6, buf);
TEST_ASSERT_STREQ("000000", buf, "000000");

pad_otp(0, 9, buf);
TEST_ASSERT_STREQ("000000000", buf, "000000000");
TEST_MAIN_END()
