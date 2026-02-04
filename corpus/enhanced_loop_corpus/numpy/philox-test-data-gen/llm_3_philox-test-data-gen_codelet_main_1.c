#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with step size greater than 1
    // Accessing elements with a fixed stride (e.g., every 4th element), wrapping within bounds
    volatile int arr[1000];
    for (i = 0; i < 250; i++) {
        for (j = 0; j < 4; j++) {
            int index = (i * 4 + j) * 4;  // Stride of 4 in linearized access
            if (index < 1000) {
                arr[index] = index;
            }
        }
    }
}
