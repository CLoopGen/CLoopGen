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
size_t* restrict idx_i = (size_t*)aligned_alloc(sizeof(size_t), q * p_1 * sizeof(size_t));
size_t* restrict idx_j = (size_t*)aligned_alloc(sizeof(size_t), q * p_1 * sizeof(size_t));
if (!idx_i || !idx_j) abort();

for (k = 1; k < q; k++) {
    for (k1 = 0; k1 < p_1; k1++) {
        size_t index = (k - 1) * p_1 + k1;
        idx_i[index] = i++;
        idx_j[index] = j++;
    }
    j += jump;
}
free(idx_i);
free(idx_j);
}
