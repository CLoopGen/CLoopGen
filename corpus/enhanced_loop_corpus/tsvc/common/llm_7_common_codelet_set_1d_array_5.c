#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t prev = 1.0;
    for (int i = 0; i < length; i++) {
        real_t inv_sq = 1. / (real_t)((i + 1) * (i + 1));
        arr[i] = inv_sq + prev;
        prev = inv_sq;
    }
}
