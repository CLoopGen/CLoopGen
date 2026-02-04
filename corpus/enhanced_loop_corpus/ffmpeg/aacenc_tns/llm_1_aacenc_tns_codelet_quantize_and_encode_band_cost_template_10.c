#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern int i;
extern float cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i, inner_i;
    int chunk_size = 16;
    for (outer_i = 0; outer_i < size; outer_i += chunk_size) {
        for (inner_i = outer_i; inner_i < size && inner_i < outer_i + chunk_size; inner_i++) {
            i = inner_i;
            cost += in[i] * in[i];
        }
    }
}
