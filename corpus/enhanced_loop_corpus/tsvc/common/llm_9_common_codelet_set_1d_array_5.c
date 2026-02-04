#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        int idx = i + 1;
        real_t square = (real_t)(idx * idx);
        real_t inv = 1.0 / square;
        arr[i] = inv * inv; // Now computing 1/(i+1)^4 instead of 1/(i+1)^2
    }
}
