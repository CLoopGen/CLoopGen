#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming an array 'arr' of size at least w2 * 2, we access every 2nd element
    int arr[1000]; // Example array for demonstration
    for (x = 0; x < w2; x += 2) {
        arr[x] = x * 2; // Strided write access with step 2
    }
}
