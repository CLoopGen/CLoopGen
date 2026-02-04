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
    for (n = 0; n < num; ++n) {
        unsigned char temp = in[n] ^ ivec[n];
        if (temp != 0) {
            out[n] = temp;
            ovec[16 + n] = temp;
        } else {
            out[n] = 0xFF;
            ovec[16 + n] = 0xFF;
        }
    }
}
