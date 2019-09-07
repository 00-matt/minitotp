#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <minitotp.h>

#define OTP_DEFAULT_LENGTH 8
#define OTP_MAX_LENGTH 12
#define TIME_STEP_DEFAULT 30

static void print_usage(FILE *stream, const char *prog) {
  fprintf(stream,
          "Usage: %s [-h] [-l length] [-t time] [-T step] <secret>\n"
          "  -h          Print this help message and quit\n"
          "  -l length   Set the password length. Defaults to %d, max is %d\n"
          "  -t time     Set the time. Defaults to current time\n"
          "  -T step     Set time step. Defaults to %d\n",
          prog, OTP_DEFAULT_LENGTH, OTP_MAX_LENGTH, TIME_STEP_DEFAULT);
}

int main(int argc, char **argv) {
  time_t now = 0;
  char otp[OTP_MAX_LENGTH + 1];
  int otp_length = OTP_DEFAULT_LENGTH;
  int opt;
  int tfnd = 0;
  int time_step = TIME_STEP_DEFAULT;

  while ((opt = getopt(argc, argv, "hl:t:T:")) != -1) {
    switch (opt) {
    case 'h':
      print_usage(stdout, argv[0]);
      return 0;
    case 'l':
      otp_length = atoi(optarg);
      if (otp_length > OTP_MAX_LENGTH) {
        fprintf(stderr, "Password length %d exceeds maximum of %d", otp_length,
                OTP_MAX_LENGTH);
        return 1;
      }
      break;
    case 't':
      now = atol(optarg);
      tfnd = 1;
      break;
    case 'T':
      time_step = atoi(optarg);
      break;
    default:
      print_usage(stderr, argv[0]);
      return 1;
    }
  }

  if (optind + 1 != argc) {
    print_usage(stderr, argv[0]);
    return 1;
  }

  if (!tfnd && time(&now) == -1) {
    perror("time");
    return -1;
  }

  mtotp_totp(argv[1], now, time_step, otp_length, otp);
  printf("%s\n", otp);
  return 0;
}
