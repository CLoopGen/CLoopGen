#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write to line with pre-incremented pointer simulation
    unsigned short *dst = line;
    for (i = x; i < maxx; i++) {
        *dst++ = Picy[i - x];
    }
}
