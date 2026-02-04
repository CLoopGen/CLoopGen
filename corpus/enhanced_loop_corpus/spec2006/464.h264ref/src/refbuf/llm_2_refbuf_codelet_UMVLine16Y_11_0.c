#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) on Picy, with bounds check to stay within limits
    int stride = 2;
    for (i = x; i < maxx; i += stride) {
        if ((i - x) < 16) {
            line[i - x] = Picy[0];
        }
    }
}
