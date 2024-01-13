#include "../../inc/core/cipher.h"
#include "../../inc/base/mix-columns.h"
#include "../../inc/base/shift-rows.h"
#include "../../inc/base/sub-bytes.h"

void modInvCipher(const unsigned char *const IN, const unsigned char *const KEY,
                  unsigned char *const s) {
  *(__uint128_t *const)s = *(const __uint128_t *const)IN;

  for (unsigned char i = 10;; --i) {
    *(__uint128_t *const)s ^= *(const __uint128_t *const)(KEY + 16 * i);

    if (i == 0)
      break;

    if (i < 10)
      invMixColumns(s);

    modInvShiftRows(KEY + 16 * i, s);
    modInvSubBytes(KEY + 16 * i, s);
  }
}

void invCipher(const unsigned char *const IN, const unsigned char *const KEY,
               unsigned char *const s) {
  *(__uint128_t *const)s = *(const __uint128_t *const)IN;

  for (unsigned char i = 10;; --i) {
    *(__uint128_t *const)s ^= *(const __uint128_t *const)(KEY + 16 * i);

    if (i == 0)
      break;

    if (i < 10)
      invMixColumns(s);

    invShiftRows(s);
    invSubBytes(s);
  }
}

void cipher(const unsigned char *const IN, const unsigned char *const KEY,
            unsigned char *const s) {
  *(__uint128_t *const)s = *(const __uint128_t *const)IN;

  for (unsigned char i = 0;; ++i) {
    *(__uint128_t *const)s ^= *(const __uint128_t *const)(KEY + 16 * i);

    if (i == 10)
      break;

    subBytes(s);
    shiftRows(s);

    if (i < 9)
      mixColumns(s);
  }
}

void modCipher(const unsigned char *const IN, const unsigned char *const KEY,
               unsigned char *const s) {
  *(__uint128_t *const)s = *(const __uint128_t *const)IN;

  for (unsigned char i = 0;; ++i) {
    *(__uint128_t *const)s ^= *(const __uint128_t *const)(KEY + 16 * i);

    if (i == 10)
      break;

    modSubBytes(KEY + 16 * (i + 1), s);
    modShiftRows(KEY + 16 * (i + 1), s);

    if (i > 8)
      continue;

    mixColumns(s);
  }
}
