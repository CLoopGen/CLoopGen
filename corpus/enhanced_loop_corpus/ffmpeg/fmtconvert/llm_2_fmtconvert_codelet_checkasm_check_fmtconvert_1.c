#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    int start = size - size / 2;
    for (i = 0; i < size; i += 2) {
        scale_arr[i] = start / 13.0f;
        if (i + 1 < size) {
            scale_arr[i + 1] = start / 13.0f;
        }
    }
}
