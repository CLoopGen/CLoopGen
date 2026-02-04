#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *base_ptr = (tmsize_t*)malloc(stride * sizeof(tmsize_t));
    tmsize_t index_array[100];
    for (i = 0; i < 100 && (stride - 4 - i*3) > 0; i++) {
        index_array[i] = stride - 4 - i*3;
    }
    for (i = 0; index_array[i] > 0 && i < 100; i++) {
        base_ptr[index_array[i]] *= 2;
    }
    free(base_ptr);
}
