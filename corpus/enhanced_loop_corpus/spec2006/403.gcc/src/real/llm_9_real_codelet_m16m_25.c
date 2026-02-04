#include <stdio.h>

#include <inttypes.h>

extern unsigned short c[];
extern unsigned short p[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with minimal operations; lightweight data transfer
    for (i = 2; i < (4 + 1); i += 2) {
        c[i] = p[i];
    }
}
