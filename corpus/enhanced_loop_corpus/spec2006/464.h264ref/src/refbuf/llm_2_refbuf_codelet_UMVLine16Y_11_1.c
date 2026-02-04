#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    for (i = 0; i < maxx; i += stride) {
        if (i < maxx) line[i - x] = Picy[i];
        if (i + 1 < maxx) line[i + 1 - x] = Picy[i + 1];
    }
}
