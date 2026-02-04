#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (; i < 36; i += 2) {
        win[1][i] = 0.;
        if (i + 1 < 36) {
            win[1][i + 1] = 0.;
        }
    }
}
