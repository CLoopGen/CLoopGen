#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (r = 0; r < num_moves; r += 2) {
        if (distances[r] > distances[0] + 1500)
            break;
    }
}
