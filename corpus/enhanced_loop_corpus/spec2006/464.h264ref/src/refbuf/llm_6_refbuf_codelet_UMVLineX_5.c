#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a WAW (Write-After-Write) and RAW (Read-After-Write) loop-carried dependency
    // by making each iteration depend on the previous one through an accumulator.
    unsigned short temp = 0;
    for (i = 0; i < maxx; i++) {
        temp += Picy[i];  // RAW: temp depends on prior update
        line[i - x] = temp;  // WAW: multiple writes to line with ordered updates via temp
    }
}
