#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vec;
extern int bits;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int temp = vec[i];
        for (int b = 0; b < bits; b++) {
            temp = temp * 2;
        }
        vec[i] = temp;
    }
}
