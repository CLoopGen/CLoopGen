#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int width;
extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    // Alters memory access pattern by iterating from the end to the beginning
    for (x = width - 1; x >= 0; x--) {
        b2[x] -= (b1[x] + b3[x] + 2) >> 2;
        b1[x] += (b0[x] + b2[x]) >> 1;
    }
}
