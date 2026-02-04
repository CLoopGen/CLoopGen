#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling the loop to access elements in a strided pattern
    // First handle even indices, then odd indices to create a strided access pattern
    for (i = 0; i < 36; i += 2)
        win[3][i] = win[1][35 - i];
    for (i = 1; i < 36; i += 2)
        win[3][i] = win[1][35 - i];
}
