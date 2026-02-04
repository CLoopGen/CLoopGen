#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 3 (forward traversal)
    for (int m = 0; m < 15; m += 3)
        temp[m] -= d1;
}
