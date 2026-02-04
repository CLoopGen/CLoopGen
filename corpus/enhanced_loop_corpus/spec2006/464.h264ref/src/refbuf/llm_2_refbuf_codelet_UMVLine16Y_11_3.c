#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int width;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    int start = (((width) > (x)) ? (width) : (x));
    int offset = start - x;
    for (i = start; i < maxx; i++, offset++)
        line[offset] = Picy[width - 1];
}
