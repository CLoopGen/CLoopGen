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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    int i;
    for (i = num - 1; i >= 0; --i) {
        out[i] = (ovec[16 + i] = in[i] ^ ivec[i]);
    }
}
