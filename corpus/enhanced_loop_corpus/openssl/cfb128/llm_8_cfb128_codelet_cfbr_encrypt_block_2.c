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
    for (n = 0; n < num; n += 2) {
        if (n + 1 < num) {
            out[n] = (ovec[16 + n] = in[n] ^ ivec[n]);
            out[n+1] = (ovec[16 + n+1] = in[n+1] ^ ivec[n+1]);
        } else {
            out[n] = (ovec[16 + n] = in[n] ^ ivec[n]);
        }
    }
}
