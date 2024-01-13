#include "../../inc/util/timer.h"
#include <stdio.h>
#include <time.h>

static struct timespec start;

void startTimer(void) { timespec_get(&start, TIME_UTC); }

void stopTimer(const long SIZE, const unsigned char CIPHER_INDEX) {
  const char *const CIPHERS[] = {"cipher", "modCipher", "invCipher",
                                 "modInvCipher"};
  struct timespec stop;
  timespec_get(&stop, TIME_UTC);
  printf("%6ldB %12s %.8fs\n%s", SIZE, CIPHERS[CIPHER_INDEX],
         stop.tv_sec - start.tv_sec + (stop.tv_nsec - start.tv_nsec) * 10e-9,
         CIPHER_INDEX == 3 ? "\n" : "");
}
