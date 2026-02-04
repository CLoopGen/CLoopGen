#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Flatten the 2D iteration into a single loop with consecutive array access
    int idx = 0;
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            values[(20 + m * 20 + n)] = 0.;
            idx++;
        }
    }
}
