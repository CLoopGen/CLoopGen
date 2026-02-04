#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate all loop-carried dependencies entirely.
    // Each iteration is fully independent — ideal for vectorization.
    // Also remove potential RAW/WAR/WAW by using local indexing and no shared state.
    for (i = 0; i < maxx; i++) {
        int idx = i - x;
        unsigned short val = Picy[i];
        line[idx] = val;
    }
}
