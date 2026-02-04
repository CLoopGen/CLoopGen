#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        out[0] ^= in[0];
        for (i = 1; i < len; i++) {
            out[i] ^= in[i] ^ out[i-1];
        }
    }
}
