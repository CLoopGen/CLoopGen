#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 4
    int arr[1024];
    int stride = 4;
    for (i = 0; i < (length >> 2); ++i) {
        arr[i * stride] = i;  // Accessing elements with a fixed stride
    }
}
