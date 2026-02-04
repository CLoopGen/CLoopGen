#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float scale_arr[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int size = sizeof(scale_arr) / sizeof(scale_arr[0]);
    const float factor = 1.0f / 13.0f;
    float base = (size - size / 2) * factor;
    for (i = 0; i < size; i++) {
        scale_arr[i] = base + (i & 1) * 0.5f; // Slight variation every other element
    }
}
