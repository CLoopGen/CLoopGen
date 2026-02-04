#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *array = (tmsize_t*)malloc(stride * sizeof(tmsize_t));
    for (i = stride - 4; i > 0; i -= 2) {
        array[i] += array[i - 1];
    }
    free(array);
}
