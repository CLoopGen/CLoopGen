#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = 0;
    for (n = 0; n < 16 && n < len; ++n) {
        unsigned char current = in[n] ^ iv[n] ^ prev;
        out[n] = current;
        prev = current;
    }
}
