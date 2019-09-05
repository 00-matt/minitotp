#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <minitotp.h>

int main(int argc, char **argv) {
  time_t now;
  char *otp;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <secret>\n", argv[0]);
    return 1;
  }

  if (time(&now) == -1) {
    perror("time");
    return -1;
  }

  otp = mtotp_totp(argv[1], now, 30, 8);
  if (!otp) {
    perror("mtotp_totp");
    return -1;
  }
  printf("%s\n", otp);
  free(otp);
  return 0;
}
