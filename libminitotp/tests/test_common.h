#ifndef TEST_COMMON_H_
#define TEST_COMMON_H_

#include <stdio.h>

#define S2(x) #x
#define S(x) S2(x)

#define TEST_MAIN_BEGIN()                                                      \
  int main() {                                                                 \
    int assertions_total = 0;                                                  \
    int assertions_fail = 0;

#define TEST_ASSERT(message, test)                                             \
  do {                                                                         \
    assertions_total++;                                                        \
    if (!(test)) {                                                             \
      assertions_fail++;                                                       \
      fputs(__FILE__ ":" S(__LINE__) " Assertion " message " failed\n",        \
            stderr);                                                           \
    }                                                                          \
  } while (0)

#define TEST_ASSERT_EQ(message, lhs, rhs) TEST_ASSERT(message, lhs == rhs)

#define TEST_MAIN_END()                                                        \
  printf("%d/%d assertions passed\n", assertions_total - assertions_fail,      \
         assertions_total);                                                    \
  return assertions_fail != 0;                                                 \
  }

#endif
