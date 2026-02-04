#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (j = 0; j < num_moves; j += 2) {
        if (rootlosers[j])
            k++;
    }
}
