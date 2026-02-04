#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 18; i += 2) {
        win[1][i] = win[0][i];       // No dependency between iterations
        if (i + 1 < 18) {
            win[1][i+1] = win[0][i+1];
        } // Eliminates loop-carried dependency by enabling potential unrolling and parallelism
    }
}
