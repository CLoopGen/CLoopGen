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
    for (i = x; i < maxx; i += 2) {
        line[(i - x)/2] = Picy[i];
    }
    // Handle odd-sized ranges if needed by processing leftover element
    if ((maxx - x) % 2 == 1 && maxx > x) {
        line[(maxx - x - 1)/2] = Picy[maxx - 1];
    }
}
