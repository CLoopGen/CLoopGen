#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access pattern
    static const int indices[] = {0,3,6,9,12,15,18,21,1,4,7,10,13,16,19,22,2,5,8,11,14,17,20,23};
    for (int j = 0; j < 24; j++) {
        win[1][indices[j]] = 1.;
    }
    i = 24; // Ensure loop condition is satisfied after completion
}
