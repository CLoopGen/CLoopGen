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
    // Variant 1: Introduce a loop-carried WAW dependency by reusing line[i - x] in a cumulative way
    // Also introduce a RAW dependency by reading previous value before writing
    for (i = (((width) > (x)) ? (width) : (x)); i < maxx; i++) {
        if (i > (((width) > (x)) ? (width) : (x))) {
            line[i - x] = line[i - x - 1] + Picy[width - 1];
        } else {
            line[i - x] = Picy[width - 1];
        }
    }
}
