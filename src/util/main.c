#include "../../inc/core/cipher.h"
#include "../../inc/core/key-expansion.h"
#include "../../inc/util/file.h"
#include "../../inc/util/test.h"
#include "../../inc/util/timer.h"

static unsigned char key[] = "dKro9Wahme#dHrn7";
static void (*const CIPHERS[])(const unsigned char *const,
                               const unsigned char *const,
                               unsigned char *const) = {
    cipher, modCipher, invCipher, modInvCipher};
static inline int table34(void), table56(void), table7(void), table8(void),
    table9(void), table91(void);

int main(void) {
  return table34() | table56() | table7() | table8() | table9() | table91();
}

static inline int table8(void) {
  {
    const long SIZE = 256 * 256;
    unsigned char w[176], in[SIZE], s[SIZE];

    readFile("data/smiley.jpg", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);
      for (long i = 0; i < SIZE; i += 16)
        CIPHERS[j](in + i, w, s + i);

      stopTimer(SIZE, j);
    }
  }
  {
    const unsigned char IN[16] = {0x00, 0x01, 0x09, 0x0e, 0x0d, 0x0a,
                                  0x07, 0x06, 0x0f, 0x02, 0x0c, 0x05,
                                  0x0a, 0x04, 0x03, 0x08};
    unsigned char s[16], w[176];

    for (unsigned char i = 0; i < 2; ++i) {
      startTimer();
      keyExpansion(key, w);
      CIPHERS[i](IN, w, s);
      stopTimer(16, i);
    }
  }
  {
    const long SIZE = 256 * 256;
    unsigned char w[176], in[SIZE], s[SIZE];

    readFile("data/smiley.jpg", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);

      for (signed char k = 3; k--;)
        for (long i = 0; i < SIZE; i += 16)
          CIPHERS[j](in + i, w, s + i);

      stopTimer(SIZE, j);
    }
  }
  {
    const long SIZE = 4.45 * 1024 * 1024;
    unsigned char w[176], *in = __builtin_malloc(SIZE), s[16];

    readFile("data/mountain.jpg", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);
      for (long i = 0; i < SIZE; i += 16)
        CIPHERS[j](in + i, w, s);

      stopTimer(SIZE, j);
    }

    __builtin_free(in);
  }
  {
    const long SIZE = 128 * 128;
    unsigned char w[176], in[SIZE], s[16];

    readFile("data/legend.png", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);
      for (long i = 0; i < SIZE; i += 16)
        CIPHERS[j](in + i, w, s);

      stopTimer(SIZE, j);
    }
  }
  {
    const long SIZE = 256 * 256;
    unsigned char w[176], in[SIZE], s[SIZE];

    readFile("data/smiley.jpg", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);

      for (signed char k = 6; k--;)
        for (long i = 0; i < SIZE; i += 16)
          CIPHERS[j](in + i, w, s + i);

      stopTimer(SIZE, j);
    }
  }
  {
    const unsigned char IN[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                                  0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
                                  0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char s[16], w[176];

    for (unsigned char i = 0; i < 2; ++i) {
      startTimer();
      keyExpansion(key, w);
      CIPHERS[i](IN, w, s);
      stopTimer(16, i);
    }
  }
  {
    const unsigned char IN[16] = {0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a,
                                  0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
                                  0x03, 0x02, 0x01, 0x00};
    unsigned char s[16], w[176];

    for (unsigned char i = 0; i < 2; ++i) {
      startTimer();
      keyExpansion(key, w);
      CIPHERS[i](IN, w, s);
      stopTimer(16, i);
    }
  }
  {
    unsigned char in[48] = "Improved AES for Data Security in Electro-Health";

    for (unsigned char k = 0; k < 2; ++k) {
      startTimer();

      unsigned char w[176], s[48];
      keyExpansion(key, w);

      for (long i = 0; i < 48; i += 16)
        CIPHERS[k](in + i, w, s + i);

      stopTimer(48, k);
    }
  }
  {
    const unsigned char KEY[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                                 0x06, 0x07, 0X08, 0X09, 0X0a, 0X0b,
                                 0X0c, 0X0d, 0X0e, 0X0f},
                        IN[16] = "ABCDEFGHIJKLMAAB";
    unsigned char s[16], w[176];

    for (unsigned char i = 0; i < 2; ++i) {
      startTimer();
      keyExpansion(KEY, w);
      CIPHERS[i](IN, w, s);
      stopTimer(16, i);
    }
  }
  {
    const long SIZE = 185 * 1024;
    unsigned char w[176], in[SIZE], s[SIZE];
    readFile("data/world.png", SIZE, in);

    for (unsigned char j = 0; j < 2; ++j) {
      startTimer();

      keyExpansion(key, w);

      for (long i = 0; i < SIZE; i += 16)
        CIPHERS[j](in + i, w, s + i);

      stopTimer(SIZE, j);
    }
  }
  return 0;
}

static inline int table91(void) {
  unsigned char in[16] = "ABCDEFGHIJKLMNOP",
                key[48] = "000102030405060708090a0b0c0d0e010011223344556677",
                w[176], s[2][16];
  float AVL[] = {40.625, 51.5625};

  for (signed char i = 2; i--;) {
    for (signed char j = 2; j--; flipBit(key, 67)) {
      keyExpansion(key, w);
      CIPHERS[i](in, w, s[j]);
    }
    float avl = avalancheEffect(*s, s[1]) / (16 / 16.);

    if (avl != AVL[i])
      return 1;
  }
  return 0;
}

static inline int table9(void) {
  {
    const long SIZE = 512 * 512;
    unsigned char in[3][SIZE], s[3][SIZE], w[176];
    const float AVL[][2] = {{49.9774246, 49.9802017}, {49.9358521, 50.0739288}};
    readFile("data/baboon.png", SIZE, in[0]);
    readFile("data/mickey.png", SIZE, in[1]);
    readFile("data/lenna.png", SIZE, in[2]);

    keyExpansion(key, w);

    for (signed char k = 2; k--;)
      for (signed char j = 2; j--;) {
        for (long i = 0; i < SIZE; i += 16) {
          CIPHERS[j](in[k] + i, w, s[k] + i);
          CIPHERS[j](in[2] + i, w, s[2] + i);
        }

        float avl = 0;
        for (long i = 0; i < SIZE; i += 16)
          avl += avalancheEffect(s[k] + i, s[2] + i) / (SIZE / 16.);
        if (avl != AVL[k][j]) {
          ;
        }
      }
  }
  return 0;
}

static inline int table7(void) {
  const long SIZES[5] = {16, 32, 64, 128, 512 * 1024};
  unsigned char in[SIZES[4]];
  readFile("data/0-5mb.txt", SIZES[4], in);

  for (unsigned char k = 0; k < 5; ++k)
    for (unsigned char j = 0; startTimer(), j < 4;
         stopTimer(SIZES[k], j), ++j) {
      unsigned char w[176], s[SIZES[k]];
      keyExpansion(key, w);

      for (long i = 0; i < SIZES[k]; i += 16)
        CIPHERS[j](in + i, w, s + i);
    }
  return 0;
}

static inline int table56(void) {
  const long SIZE = 512 * 1024;
  unsigned char in[SIZE];
  readFile("data/0-5mb.txt", SIZE, in);

  const float AVL[][2] = {{49.9948845, 50.0157089}, {49.9221992, 49.9485168}};
  const unsigned long FLIP_NS[] = {112, 3751};
  unsigned char *const flipBufs[] = {key, in};

  for (unsigned char l = 0; l < 2; ++l)
    for (unsigned char s[2][SIZE], k = 0; k < 2; ++k) {
      for (unsigned char j = 0; j < 2; ++j, flipBit(flipBufs[l], FLIP_NS[l])) {
        unsigned char w[176];
        keyExpansion(key, w);

        for (long i = 0; i < SIZE; i += 16) {
          const unsigned char IN[16];
          *(__uint128_t *const)IN = i ? *(const __uint128_t *const)(in + i) ^
                                            *(__uint128_t *const)(s[j] + i - 16)
                                      : 0;
          CIPHERS[k](IN, w, s[j] + i);
        }
      }

      float avl = 0;

      for (long i = 0; i < SIZE; i += 16)
        avl += avalancheEffect(*s + i, s[1] + i) / (SIZE / 16.);

      if (avl != AVL[l][k])
        return 1;
    }
  return 0;
}

static inline int table34(void) {
  unsigned char in[] = "I Love Unilorin!";

  const __uint128_t ENCS[][2][2] = {
      {{*(const __uint128_t *const)(const unsigned char[]){
            0x55, 0xe3, 0x2, 0xbf, 0x16, 0xf6, 0x2a, 0xa7, 0xdd, 0xe7, 0x3a,
            0xdf, 0x29, 0x78, 0x36, 0xa7},
        *(const __uint128_t *const)(const unsigned char[]){
            0xed, 0x9e, 0xbb, 0xe5, 0x1b, 0xbb, 0xc0, 0xaf, 0xbb, 0x3d, 0xe2,
            0x7, 0xc4, 0xd1, 0xd0, 0x50}},
       {*(const __uint128_t *const)(const unsigned char[]){
            0xd6, 0xba, 0x33, 0x8a, 0xc3, 0x61, 0x3a, 0x74, 0xb5, 0xfb, 0xeb,
            0xa4, 0xea, 0x97, 0xb1, 0x10},
        *(const __uint128_t *const)(const unsigned char[]){
            0x5d, 0x2d, 0xa4, 0x39, 0x11, 0x04, 0x95, 0xc8, 0x2e, 0x17, 0xd3,
            0x7f, 0x5c, 0x43, 0x22, 0x86}}},
      {{*(const __uint128_t *const)(const unsigned char[]){
            0x55, 0xe3, 0x2, 0xbf, 0x16, 0xf6, 0x2a, 0xa7, 0xdd, 0xe7, 0x3a,
            0xdf, 0x29, 0x78, 0x36, 0xa7},
        *(const __uint128_t *const)(const unsigned char[]){
            0x5e, 0x7a, 0xd2, 0xbb, 0xff, 0x9b, 0xa1, 0x86, 0x19, 0xbd, 0xb1,
            0x48, 0x40, 0xa9, 0x26, 0x8e}},
       {*(const __uint128_t *const)(const unsigned char[]){
            0xd6, 0xba, 0x33, 0x8a, 0xc3, 0x61, 0x3a, 0x74, 0xb5, 0xfb, 0xeb,
            0xa4, 0xea, 0x97, 0xb1, 0x10},
        *(const __uint128_t *const)(const unsigned char[]){
            0x5d, 0xcc, 0x92, 0x69, 0x1e, 0xc2, 0x74, 0xb4, 0xe7, 0xeb, 0x7e,
            0x3, 0xd1, 0xde, 0x2, 0xd3}}}};
  const float AVLS[][2] = {{55.46875, 57.8125}, {42.96875, 49.21875}};
  unsigned char *const flipBufs[] = {key, in};
  const unsigned long flipNs[] = {112, 88};

  for (unsigned char k = 0; k < 2; ++k)
    for (unsigned char s[2][16], j = 0; j < 2; ++j) {
      for (unsigned char i = 0; i < 2; ++i, flipBit(flipBufs[k], flipNs[k])) {
        unsigned char w[176];
        keyExpansion(key, w);
        CIPHERS[j](in, w, s[i]);

        if (ENCS[k][j][i] != *(__uint128_t *)s[i])
          return 1;
      }
      if (avalancheEffect(*s, s[1]) != AVLS[k][j])
        return 1;
    }
  return 0;
}
