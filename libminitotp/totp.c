#include <minitotp.h>

char *mtotp_totp(const char *secret, uint64_t time, int time_step, int length,
                 char *buf) {
  uint64_t interval = time / time_step;
  return mtotp_hotp(secret, interval, length, buf);
}
