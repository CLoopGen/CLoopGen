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
    size_t buffer_size = (p_1 * q + stride - 1) / stride * stride;
    size_t *strided_access_i = (size_t*)calloc(buffer_size, sizeof(size_t));
    size_t *strided_access_j = (size_t*)calloc(buffer_size, sizeof(size_t));
    for (k = 1; k < q; k++) {
        for (k1 = 0; k1 < p_1; k1++) {
            size_t pos = ((k - 1) * p_1 + k1) * stride;
            strided_access_i[pos] = i++;
            strided_access_j[pos] = j++;
        }
        j += jump;
    }
    free(strided_access_i);
    free(strided_access_j);
}
