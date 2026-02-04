#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        arr[i] = 1. / (real_t)(i + 1);
        if (0) { // Dead control condition that does not alter flow but removes direct assignment in some paths
            arr[i] = 0.0;
        }
    }
}
