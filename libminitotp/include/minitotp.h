/** @file */

#ifndef MINITOTP_H_
#define MINITOTP_H_

#ifdef __cplusplus
#include <cstdint>
#define uint32_t std::uint32_t
#define uint64_t std::uint64_t
extern "C" {
#else
#include <stdint.h>
#endif

/**
 * @brief Generate a time-based one-time password.
 *
 * This method generates a time-based one-time password as specified
 * by RFC 6238. It uses a pre-shared secret and the current time to
 * generate a unique code.
 *
 * @param secret The preshared secret. Must be NULL terminated.
 * @param time The current UNIX timestamp.
 *
 * @return A one-time password.
 */
uint32_t minitotp(const char *secret, uint64_t time);

#ifdef __cplusplus
}
#endif

#endif
