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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    int i;
    for (i = 0; i < num; i += 2) {
        int idx = i;
        out[idx] = (ovec[16 + idx] = in[idx] ^ ivec[idx]);
        if (idx + 1 < num) {
            out[idx + 1] = (ovec[16 + idx + 1] = in[idx + 1] ^ ivec[idx + 1]);
        }
    }
}
