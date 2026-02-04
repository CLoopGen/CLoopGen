#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming existence of an array 'arr' and size 'h'
    // Access every 4th element in a strided manner
    int arr[1000]; // example array
    for (i = 0; i < h; i += 4) {
        arr[i] = i * 2; // example write with stride 4
    }
}
