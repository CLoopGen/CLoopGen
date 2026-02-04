#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;
extern real_t value;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp = value;
    for (int i = 0; i < length; i += stride) {
        arr[i] = temp;
        temp = arr[i]; // Introduce RAW (read-after-write) and create a loop-carried dependency
    }
}
