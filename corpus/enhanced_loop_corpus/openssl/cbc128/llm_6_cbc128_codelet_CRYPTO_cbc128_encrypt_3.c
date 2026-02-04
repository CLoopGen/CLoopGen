#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[16];
    for (size_t i = 0; n < 16; ++n, ++i)
        temp[i] = iv[n];
    for (size_t i = 0; i < 16 && (n - 16 + i) < 16; ++i)
        out[i] = temp[i];
}
