#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and minimal operations
    for (i = x; i < maxx && (i - x) < 16; i++) {
        line[i - x] = Picy[i] & 0xFFFE;  // Clear the least significant bit
    }
}
