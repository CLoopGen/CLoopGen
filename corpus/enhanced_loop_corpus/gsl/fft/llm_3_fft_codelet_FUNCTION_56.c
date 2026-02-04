#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *array = (size_t*)malloc(q * sizeof(size_t));
    size_t stride = 2;
    for (k1 = 0; k1 < q; k1 += stride) {
        if (k1 < q) {
            array[k1] = k1 * 3; // Strided access: every second element
        }
    }
    free(array);
}
