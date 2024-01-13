#include "../../inc/base/shift-rows.h"

static inline void sort(unsigned char *const val) {
  unsigned char mid0, mid1, min0, max0, min1, max1;

  if (val[0] < val[1])
    min0 = val[0], max0 = val[1];
  else
    min0 = val[1], max0 = val[0];

  if (val[2] < val[3])
    min1 = val[2], max1 = val[3];
  else
    min1 = val[3], max1 = val[2];

  if (min0 < min1)
    val[0] = min0, mid0 = min1;
  else
    val[0] = min1, mid0 = min0;

  if (max0 > max1)
    val[3] = max0, mid1 = max1;
  else
    val[3] = max1, mid1 = max0;

  if (mid0 < mid1)
    val[1] = mid0, val[2] = mid1;
  else
    val[2] = mid0, val[1] = mid1;
}

void modInvShiftRows(const unsigned char *const KEY, unsigned char *const s) {
  const unsigned char Val[4] = {
      s[0] ^ KEY[0] ^ s[1] ^ KEY[1] ^ s[2] ^ KEY[2] ^ s[3] ^ KEY[3],
      s[4] ^ KEY[4] ^ s[5] ^ KEY[5] ^ s[6] ^ KEY[6] ^ s[7] ^ KEY[7],
      s[8] ^ KEY[8] ^ s[9] ^ KEY[9] ^ s[10] ^ KEY[10] ^ s[11] ^ KEY[11],
      s[12] ^ KEY[12] ^ s[13] ^ KEY[13] ^ s[14] ^ KEY[14] ^ s[15] ^ KEY[15],
  };
  unsigned char sortedVal[4] = {Val[0], Val[1], Val[2], Val[3]}, No[4];

  sort(sortedVal);
  for (signed char i = 3; i >= 0; --i)
    for (signed char j = 3; j >= 0; --j)
      if (Val[i] == sortedVal[j])
        No[i] = j;

  for (signed char i = 3; i >= 0; --i) {
    unsigned char *const ROW = s + (i << 2), tmp[4];
    *(unsigned *)tmp = *(unsigned *)ROW;

    *ROW = tmp[-No[i] & 3], ROW[1] = tmp[(1 - No[i]) & 3],
    ROW[2] = tmp[(2 - No[i]) & 3], ROW[3] = tmp[(3 - No[i]) & 3];
  }
}

void modShiftRows(const unsigned char *const KEY, unsigned char *const s) {
  const unsigned char VAL[4] = {
      s[0] ^ KEY[0] ^ s[1] ^ KEY[1] ^ s[2] ^ KEY[2] ^ s[3] ^ KEY[3],
      s[4] ^ KEY[4] ^ s[5] ^ KEY[5] ^ s[6] ^ KEY[6] ^ s[7] ^ KEY[7],
      s[8] ^ KEY[8] ^ s[9] ^ KEY[9] ^ s[10] ^ KEY[10] ^ s[11] ^ KEY[11],
      s[12] ^ KEY[12] ^ s[13] ^ KEY[13] ^ s[14] ^ KEY[14] ^ s[15] ^ KEY[15],
  };
  unsigned char sortedVal[4] = {VAL[0], VAL[1], VAL[2], VAL[3]}, No[4];

  sort(sortedVal);
  for (signed char i = 3; i >= 0; --i)
    for (signed char j = 3; j >= 0; --j)
      if (VAL[i] == sortedVal[j])
        No[i] = j;

  for (signed char i = 3; i >= 0; --i) {
    unsigned char *const ROW = s + (i << 2);
    const unsigned char tmp[4]; // = {*ROW, ROW[1], ROW[2], ROW[3]};
    *(unsigned *)tmp = *(unsigned *)ROW;

    *ROW = tmp[No[i] & 3], ROW[1] = tmp[(1 + No[i]) & 3],
    ROW[2] = tmp[(2 + No[i]) & 3], ROW[3] = tmp[(3 + No[i]) & 3];
  }
}

void shiftRows(unsigned char *const s) {
  unsigned char tmp = s[1];

  s[1] = s[5], s[5] = s[9], s[9] = s[13], s[13] = tmp, tmp = s[2], s[2] = s[10],
  s[10] = tmp, tmp = s[6], s[6] = s[14], s[14] = tmp, tmp = s[3], s[3] = s[15],
  s[15] = s[11], s[11] = s[7], s[7] = tmp;
}

void invShiftRows(unsigned char *const s) {
  unsigned char tmp = s[13];

  s[13] = s[9], s[9] = s[5], s[5] = s[1], s[1] = tmp, tmp = s[2], s[2] = s[10],
  s[10] = tmp, tmp = s[6], s[6] = s[14], s[14] = tmp, tmp = s[3], s[3] = s[7],
  s[7] = s[11], s[11] = s[15], s[15] = tmp;
}
