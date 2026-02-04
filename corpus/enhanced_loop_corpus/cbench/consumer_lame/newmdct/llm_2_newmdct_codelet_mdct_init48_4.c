#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolling the loop to access every second element
    for (; i < 24; i += 2) {
        win[1][i] = 1.;
        if (i + 1 < 24) {
            win[1][i + 1] = 1.;
        }
    }
}
