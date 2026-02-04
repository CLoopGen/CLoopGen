#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;
extern real_t value;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (remove stride, access every element)
    for (int i = 0; i < length; ++i) {
        arr[i] = value;
    }
}
