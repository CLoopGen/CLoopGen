#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies by unrolling and reordering accesses
    // assuming maxx is a multiple of 4 and small enough (<=16)
    int limit = maxx - (maxx % 4);  // Ensure we don't exceed bounds when unrolling
    for (i = 0; i < limit; i += 4) {
        line[i + 0 - x] = Picy[i + 0];
        line[i + 1 - x] = Picy[i + 1];
        line[i + 2 - x] = Picy[i + 2];
        line[i + 3 - x] = Picy[i + 3];
    }
    // Handle remainder
    for (; i < maxx; i++) {
        line[i - x] = Picy[i];
    }
}
