#include "../../inc/util/file.h"
#include <stdio.h>

void readFile(const char *const FILE_NAME, const long SIZE,
              unsigned char *const buf) {
  FILE *const P_file = fopen(FILE_NAME, "r");
  fread(buf, 1, SIZE, P_file);
  fclose(P_file);
}
