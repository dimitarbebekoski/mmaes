#include "../../inc/base/sub-bytes.h"
#include "../../inc/core/key-expansion.h"

static const unsigned char RCON[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 27, 54};
static inline void rotWord(unsigned char *const w);

void keyExpansion(const unsigned char *const KEY, unsigned char *const w) {
  *(__uint128_t *const)w = *(const __uint128_t *const)KEY;

  for (unsigned char i = 4; i < 44; ++i) {
    const unsigned char *const w0 = w + 4 * i;
    unsigned char tmp[4];

    *(unsigned *const)tmp = *(unsigned *const)(w0 - 4);

    if (!(i & 3))
      rotWord(tmp), subWord(tmp), *tmp ^= RCON[i >> 2];

    *(unsigned *const)w0 = *(unsigned *const)(w0 - 16) ^ *(unsigned *const)tmp;
  }
}

static inline void rotWord(unsigned char *const w) {
  const unsigned char tmp = *w;
  *w = w[1], w[1] = w[2], w[2] = w[3], w[3] = tmp;
}
