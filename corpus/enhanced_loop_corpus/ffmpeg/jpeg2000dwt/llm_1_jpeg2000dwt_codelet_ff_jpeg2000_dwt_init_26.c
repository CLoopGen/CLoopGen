#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int border[2][2];
extern int i;
extern int j;
extern int b[2][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Linearized (consecutive) memory access using flattened indexing
    int *bp = &b[0][0];
    int *borderp = &border[0][0];
    for (int idx = 0; idx < 4; idx++)
        bp[idx] = borderp[idx];
}
