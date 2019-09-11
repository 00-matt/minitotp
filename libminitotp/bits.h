#ifndef MINITOTP_BITS_H_
#define MINITOTP_BITS_H_

#define BIG_ENDIAN 4321
#define LITTLE_ENDIAN 1234

#include <stdint.h>

#ifndef BYTE_ORDER
#ifdef __linux__
#include <endian.h>
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#include <sys/endian.h>
#else
#error "Unknown endianness. Please define BYTE_ORDER"
#endif
#endif

#ifndef htobe64
#if BYTE_ORDER == LITTLE_ENDIAN
#define htobe64(x)                                                             \
  ((uint64_t)((((uint64_t)(x)&0xff00000000000000ull) >> 56) |                  \
              (((uint64_t)(x)&0x00ff000000000000ull) >> 40) |                  \
              (((uint64_t)(x)&0x0000ff0000000000ull) >> 24) |                  \
              (((uint64_t)(x)&0x000000ff00000000ull) >> 8) |                   \
              (((uint64_t)(x)&0x00000000ff000000ull) << 8) |                   \
              (((uint64_t)(x)&0x0000000000ff0000ull) << 24) |                  \
              (((uint64_t)(x)&0x000000000000ff00ull) << 40) |                  \
              (((uint64_t)(x)&0x00000000000000ffull) << 56)))
#elif BYTE_ORDER == BIG_ENDIAN
#define htobe64(x) (x)
#else
#error "Unknown BYTE_ORDER"
#endif
#endif

#endif
