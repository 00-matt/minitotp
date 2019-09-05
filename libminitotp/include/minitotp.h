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
 *
 * @return The one-time password as an ASCII string. Must be
 *         freed by the caller. May be NULL if malloc fails.
 */
char *mtotp_hotp(const char *secret, uint64_t counter, int length);

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
 *
 * @return A one-time password as an ASCII string. Must be
 *         freed by the caller . May be NULL if malloc fails.
 */
char *mtotp_totp(const char *secret, uint64_t time, int time_step, int length);

#ifdef __cplusplus
}
#endif

#endif
