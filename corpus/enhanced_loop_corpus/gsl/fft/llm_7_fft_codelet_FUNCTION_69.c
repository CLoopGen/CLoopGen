#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k;
extern size_t k1;
extern  size_t q;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *array = (size_t*)malloc(q * sizeof(size_t));
    if (!array) return;
    for (k = 1; k < (product_1 + 1) / 2; k++) {
        for (k1 = 0; k1 < q; k1++) {
            array[k1] = k * k1; // WAW: each iteration writes to distinct location; no loop-carried dep
        }
    }
    // Break data dependency across outer iterations by writing independent values
    free(array);
}
