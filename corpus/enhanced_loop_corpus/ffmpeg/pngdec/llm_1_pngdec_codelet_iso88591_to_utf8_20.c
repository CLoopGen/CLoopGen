#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t extra;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t chunk_size = 16;
    size_t outer_iters = (size_in + chunk_size - 1) / chunk_size;
    size_t i_outer, i_inner;

    for (i_outer = 0; i_outer < outer_iters; i_outer++) {
        for (i_inner = 0; i_inner < chunk_size; i_inner++) {
            size_t idx = i_outer * chunk_size + i_inner;
            if (idx < size_in) {
                extra += in[idx] >= 128;
            }
        }
    }
}
