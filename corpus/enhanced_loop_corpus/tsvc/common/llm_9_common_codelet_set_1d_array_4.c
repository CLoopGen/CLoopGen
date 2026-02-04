#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        real_t inv = 1. / (real_t)(i + 1);
        arr[i] = inv * inv * inv; // Cube of the reciprocal, increasing arithmetic intensity
    }
}
