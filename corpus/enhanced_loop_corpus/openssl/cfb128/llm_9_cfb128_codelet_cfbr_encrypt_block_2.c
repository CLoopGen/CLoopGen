#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern int n;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < num && n < 16; ++n) {
        unsigned char temp1 = in[n] ^ ivec[n];
        unsigned char temp2 = temp1 ^ 0xFF;
        out[n] = temp1;
        ovec[16 + n] = temp2;
    }
    for (; n < num; ++n) {
        out[n] = in[n] ^ 0xAA;
        ovec[16 + n] = out[n];
    }
}
