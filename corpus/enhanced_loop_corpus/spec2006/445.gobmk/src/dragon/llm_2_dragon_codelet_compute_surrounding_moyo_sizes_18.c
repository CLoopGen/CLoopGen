#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal order
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (int i = end - 1; i >= start; i--) {
        moyo_sizes[i] = 0.;
        moyo_values[i] = 0.;
    }
    pos = start; // restore pos to expected value after loop
}
