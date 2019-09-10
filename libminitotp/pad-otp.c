#include "pad-otp.h"

void pad_otp(uint32_t code, unsigned length, char *buf) {
  unsigned i;
  unsigned len;
  char *pbuf = buf;

  do {
    int digit = code % 10;
    *(pbuf++) = '0' + digit;
    code /= 10;
  } while (code > 0);

  for (i = (pbuf - buf); i < length; i++) {
    *(pbuf++) = '0';
  }

  *pbuf = '\0';

  len = pbuf - buf;

  for (i = 0; i < len / 2; i++) {
    char tmp = buf[i];
    buf[i] = buf[len - i - 1];
    buf[len - i - 1] = tmp;
  }
}
