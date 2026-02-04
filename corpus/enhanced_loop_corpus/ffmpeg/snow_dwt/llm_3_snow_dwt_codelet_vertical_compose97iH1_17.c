#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    for (i = width - 1; i >= 0; i--) {
        b1[i] -= (1 * (b0[i] + b2[i]) + 0) >> 0;
    }
}
