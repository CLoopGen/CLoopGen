#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (len < 16) ? len : 16;
    for (n = 0; n < limit; ++n) {
        unsigned char temp = in[n] + iv[n];
        out[n] = (temp ^ in[n]) ^ (iv[n] ^ temp);
    }
}
