#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < Alphabet_size; i++) {
        if (i > 0) {
            Degenerate[i][i] = Degenerate[i-1][i-1] + 1; // Introduce RAW dependency: current depends on previous iteration
        } else {
            Degenerate[i][i] = 1;
        }
        DegenCount[i] = i + 1; // WAW hazard possible if parallelized; loop-carried dependence on i
    }
}
