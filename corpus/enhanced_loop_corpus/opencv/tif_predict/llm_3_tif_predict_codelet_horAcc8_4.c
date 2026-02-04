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
    tmsize_t index_array[4] = {stride - 4, stride - 2, stride - 6, stride - 8};
    for (i = 0; i < 4; i++) {
        base_ptr[index_array[i]] *= 2;
    }
    free(base_ptr);
}
