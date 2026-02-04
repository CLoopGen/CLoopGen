#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = x; i < maxx; i += 2) {
        int idx = i - x;
        line[idx] = Picy[i] + (Picy[i] >> 4);
        if (i + 1 < maxx) {
            line[idx + 1] = Picy[i + 1] + (Picy[i + 1] >> 4);
        }
    }
}
