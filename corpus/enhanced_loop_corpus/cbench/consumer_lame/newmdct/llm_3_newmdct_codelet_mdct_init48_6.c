#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using an index remapping to maintain correctness
    // Instead of accessing 35-i directly, precompute the reverse index in a consecutive forward sweep
    int idx;
    for (i = 0, idx = 35; i < 36; i++, idx--)
        win[3][i] = win[1][idx];
}
