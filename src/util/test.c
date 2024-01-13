#include "../../inc/util/test.h"

float avalancheEffect(const unsigned char *const X,
                      const unsigned char *const Y) {
  const unsigned long *const XX = (const unsigned long *const)X;
  const unsigned long *const YY = (const unsigned long *const)Y;
  return (__builtin_popcountl(XX[0] ^ YY[0]) +
          __builtin_popcountl(XX[1] ^ YY[1])) *
         100 / (16. * 8);
}

void flipBit(unsigned char *const str, const unsigned long K) {
  str[(K >> 3) - 1] ^= 1 << (K & 7);
}
