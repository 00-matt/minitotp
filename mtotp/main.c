#include <stdio.h>
#include <time.h>

#include <minitotp.h>

int main(int argc, char **argv) {
  time_t now;
  uint64_t otp;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <secret>\n", argv[0]);
    return 1;
  }

  if (time(&now) == -1) {
    perror("time");
    return -1;
  }

  otp = minitotp(argv[1], now);
  printf("%lu\n", otp);
  return 0;
}
