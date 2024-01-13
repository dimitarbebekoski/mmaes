#ifndef CIPHER_H
#define CIPHER_H

void cipher(const unsigned char *const, const unsigned char *const,
            unsigned char *const);
void invCipher(const unsigned char *const, const unsigned char *const,
               unsigned char *const);
void modCipher(const unsigned char *const, const unsigned char *const,
            unsigned char *const);
void modInvCipher(const unsigned char *const, const unsigned char *const,
            unsigned char *const);

#endif
