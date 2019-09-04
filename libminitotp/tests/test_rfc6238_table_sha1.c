#include <minitotp.h>

#include "test_common.h"

static const char secret[] = "12345678901234567890";

TEST_MAIN_BEGIN()
TEST_ASSERT_EQ("time = 59", minitotp(secret, 59), 94287082);

// TODO: 0 padding
TEST_ASSERT_EQ("time = 1111111109", minitotp(secret, 1111111109), 7081804);

TEST_ASSERT_EQ("time = 1111111111", minitotp(secret, 1111111111), 14050471);

TEST_ASSERT_EQ("time = 1234567890", minitotp(secret, 1234567890), 89005924);

TEST_ASSERT_EQ("time = 2000000000", minitotp(secret, 2000000000), 69279037);

TEST_ASSERT_EQ("time = 20000000000", minitotp(secret, 20000000000), 65353130);
TEST_MAIN_END()
