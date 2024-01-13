#ifndef SHIFT_ROWS_H
#define SHIFT_ROWS_H

void modShiftRows(const unsigned char *const, unsigned char *const);
void modInvShiftRows(const unsigned char *const KEY, unsigned char *const s);
void shiftRows(unsigned char *const);
void invShiftRows(unsigned char *const);

#endif
