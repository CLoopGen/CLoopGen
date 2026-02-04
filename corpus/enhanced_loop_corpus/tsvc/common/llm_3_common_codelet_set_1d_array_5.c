#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (int i = length - 1; i >= 0; i--) {
        arr[i] = 1. / (real_t)((i + 1) * (i + 1));
    }
}
