#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse the array from the last element to the first
    for (i = 90; i >= 0; i--) {
        initvalu_temp[i] = initvalu[i];
    }
}
