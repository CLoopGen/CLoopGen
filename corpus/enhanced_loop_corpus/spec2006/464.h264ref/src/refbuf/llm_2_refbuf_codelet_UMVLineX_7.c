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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of writing scattered values to line[], accumulate consecutive writes
    // by reversing the iteration and using a local index to ensure sequential access.
    int start = (((width) > (x)) ? (width) : (x));
    int offset = start - x;
    for (i = start; i < maxx; i++) {
        line[offset++] = Picy[width - 1];
    }
}
