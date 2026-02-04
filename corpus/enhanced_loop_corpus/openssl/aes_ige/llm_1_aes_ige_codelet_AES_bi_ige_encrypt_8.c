#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 1; ++i)
        for (size_t j = 0; j < 16; ++j)
            out[j] = in[j] ^ iv[j];
}
