#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 3; i += 3) {
        int idx = i / 3;
        out[idx] ^= in[idx] ^ (in[idx] >> 1) ^ (in[idx] << 1);
    }
}
