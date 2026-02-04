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
    size_t *array_i = (size_t*)malloc(p_1 * q * sizeof(size_t));
    size_t *array_j = (size_t*)malloc(p_1 * q * sizeof(size_t));
    size_t idx = 0;
    for (k = 1; k < q; k++) {
        for (k1 = 0; k1 < p_1; k1++) {
            array_i[idx] = i++;
            array_j[idx] = j++;
            idx++;
        }
        j += jump;
    }
    free(array_i);
    free(array_j);
}
