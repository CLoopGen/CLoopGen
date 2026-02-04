#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from high to low index
    int j;
    for (j = 35; j >= i; j--) {
        win[1][j] = 0.;
    }
    i = 36; // Ensure loop condition is satisfied after reverse traversal
}
