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
    // Variant 2: Consecutive reverse traversal from end to start
    // Iterates backward through the arrays, accessing elements consecutively in reverse order
    for (i = width - 1; i >= 0; i--)
        b1[i] += (1 * (b0[i] + b2[i]) + 4 * b1[i] + 8) >> 4;
}
