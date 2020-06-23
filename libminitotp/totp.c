#include <minitotp.h>

#include <string.h>

char *mtotp_totp_l(const char *secret, size_t secret_len, uint64_t time,
                   int time_step, int length, char *buf) {
  uint64_t interval = time / time_step;
  return mtotp_hotp_l(secret, secret_len, interval, length, buf);
}

char *mtotp_totp(const char *secret, uint64_t time, int time_step, int length,
                 char *buf) {
  const size_t secret_len = strlen(secret);
  return mtotp_totp_l(secret, secret_len, time, time_step, length, buf);
}
