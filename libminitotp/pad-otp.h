#ifndef MINITOTP_PAD_OTP_H_
#define MINITOTP_PAD_OTP_H_

#include <stdint.h>

void pad_otp(uint32_t code, unsigned length, char *buf);

#endif
