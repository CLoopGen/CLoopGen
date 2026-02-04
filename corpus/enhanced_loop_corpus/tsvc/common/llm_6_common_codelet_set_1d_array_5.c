#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t *local_arr = arr;
    int local_length = length;
    for (int i = 0; i < local_length; i++) {
        real_t temp = 1. / (real_t)((i + 1) * (i + 1));
        local_arr[i] = temp;
    }
}
