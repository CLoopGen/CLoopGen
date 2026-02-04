#include <stdio.h>

#include <inttypes.h>

extern int goal_worm[15];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 3 (wrapping using modulo)
    for (int k = 0; k < 15; k++) {
        int index = (k * 3) % 15;
        goal_worm[index] = 0;
    }
}
