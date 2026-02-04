#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern size_t k1;
extern  size_t q;
extern  size_t p_1;
extern  size_t jump;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 4;
    size_t *buffer_i = (size_t*)calloc(q * stride * p_1, sizeof(size_t));
    size_t *buffer_j = (size_t*)calloc(q * stride * p_1, sizeof(size_t));
    for (k = 1; k < q; k++) {
        for (k1 = 0; k1 < p_1; k1++) {
            size_t addr = (k * stride * p_1 + k1) % (q * stride * p_1);
            buffer_i[addr] = ++i;
            buffer_j[addr] = ++j;
        }
        j += jump;
    }
    free(buffer_i);
    free(buffer_j);
}
