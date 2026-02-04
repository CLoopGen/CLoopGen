#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double **pointers_to_data;
extern double ***pointers_to_pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (y > 0) ? y : 1;
    int limit = x * stride;
    for (i = 0; i < limit; i += stride) {
        int scaled_i = i / stride;
        pointers_to_pointers[scaled_i] = pointers_to_data + i;
    }
}
