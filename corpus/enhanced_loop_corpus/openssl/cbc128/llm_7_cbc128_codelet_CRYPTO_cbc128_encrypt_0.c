#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char acc = 0;
    for (n = 0; n < 16; ++n) {
        acc ^= in[n] ^ iv[n];
        out[n] = acc;
    }
}
