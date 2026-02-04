#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp = 0.0;
    for (int i = 0; i < length; i++) {
        temp = 1. / (real_t)(i + 1);
        arr[i] = temp;
    }
}
