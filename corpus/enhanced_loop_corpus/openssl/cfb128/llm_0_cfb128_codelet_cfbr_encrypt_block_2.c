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
    for (int outer = 0; outer < num; ++outer) {
        for (int inner = 0; inner < 1; ++inner) {
            out[outer] = (ovec[16 + outer] = in[outer] ^ ivec[outer]);
        }
    }
}
