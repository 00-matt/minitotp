# MiniTOTP
> Application and library for time-based one-time passwords as
> specified by [RFC 6238](https://tools.ietf.org/html/rfc6238)

### Requirements

##### For libminitotp and mtotp:

* A C99 compatible C compiler
* CMake

##### For mtotp:

* A POSIX.1-2001 compatible libc

### Installation

```bash
# Grab dependencies (as root)
apt install \
  cmake \
  gcc \
  git \
  libc-dev
  
# Download source via Git and optionally checkout a specific tag
git clone https://github.com/00-matt/minitotp.git
cd minitotp
git checkout v2.0.3

# OR download a source tarball
curl -sfLo minitotp-2.0.3.tar.gz https://github.com/00-matt/minitotp/archive/v2.0.3.tar.gz
tar -xf minitotp-2.0.3.tar.gz
cd minitotp-2.0.3

# Create build directory and generate build files
mkdir build
cd $_
cmake -DCMAKE_BUILD_TYPE=Release ..

# Build
make -j$(nproc)

# Run tests
make test

# Install (as root)
make install
```

### Build options

* `-DBUILD_MTOTP=OFF|ON` - If set to ON, builds the `mtotp` command-line utility. 
* `-DBUILD_SHARED_LIBS=OFF|ON` - If set to ON, builds `libminitotp` as a shared library.
  If set to OFF, builds `libminitotp` as a static library.
* `-DBUILD_TESTS=OFF|ON` - If set to ON, builds unit tests.

### Usage

##### libminitotp

###### API

```c
/**
 * @brief Generate a one-time password.
 *
 * This method generates a one-time password as specified by RFC
 * 4226. It uses a pre-shared secret and a counter to generate a
 * unique code.
 *
 * @param secret The preshared secret. Must be NULL terminated.
 * @param counter An 8-byte counter that changes after every
 *                login attempt. Should be synchronised between
 *                client and server.
 * @param length Length of the produced one-time password. Must
 *               be at least 6.
 * @param buf A buffer to store the OTP in. Must be at least
 *            length + 1 bytes.
 *
 * @return The one-time password as an ASCII string.
 */
char *mtotp_hotp(const char *secret, uint64_t counter, int length, char *buf);

/**
 * @brief Generate a time-based one-time password.
 *
 * This method generates a time-based one-time password as specified
 * by RFC 6238. It uses a pre-shared secret and the current time to
 * generate a unique code.
 *
 * @param secret The preshared secret. Must be NULL terminated.
 * @param time The current UNIX timestamp.
 * @param time_step How often the OTP changes. Default is 30.
 * @param length Length of the produced one-time password. Must
 *               be at least 6.
 * @param buf A buffer to store the OTP in. Must be at least
 *            length + 1 bytes.
 *
 * @return The one-time password as an ASCII string.
 */
char *mtotp_totp(const char *secret, uint64_t time, int time_step, int length,
                 char *buf);
```

###### Example

```c
#include <stdio.h> // for printf()
#include <time.h> // for time_t and time()

#include <minitotp.h> // for mtotp_totp()

void print_totp(void) {
  time_t now;
  char otp[7]; // must be at least length + 1
  
  // get current time
  time(&now);
  
  // create otp
  mtotp_totp("preshared secret", now, 30, 6, otp);
  
  // print
  printf("%s\n", otp);
}
```

##### mtotp

###### Arguments

```
Usage: mtotp [-h] [-l length] [-t time] [-T step] <secret>
  -h          Print this help message and quit
  -l length   Set the password length. Defaults to 8, max is 12
  -t time     Set the time. Defaults to current time
  -T step     Set time step. Defaults to 30
```

###### Example

```
mtotp -l 6 d077f244def8a70e5ea758bd8352fcd8
```

### License

Released under the terms of the MIT license.
See [LICENSE](LICENSE) for more details.
