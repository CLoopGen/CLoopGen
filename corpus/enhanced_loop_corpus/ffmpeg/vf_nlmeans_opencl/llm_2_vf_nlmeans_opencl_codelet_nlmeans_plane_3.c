#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nb_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_pixel / 4; i++) {
        // Variant 1: Strided memory access pattern
        // Assuming an array 'data' exists, access every 4th element consecutively in the loop
        // Here we simulate accessing elements with stride of 4
        int index = i * 4;
        // Example operation (commented since no actual array is passed)
        // data[index] = data[index] * 2;
    }
}
