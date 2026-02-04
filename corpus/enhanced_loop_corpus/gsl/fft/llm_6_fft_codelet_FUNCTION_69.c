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
    size_t temp = 0;
    for (k = 1; k < (product_1 + 1) / 2; k++) {
        temp += k; // Introduce WAW dependency on temp, loop-carried via accumulation
        for (k1 = 0; k1 < q; k1++) {
            temp = temp + k1; // RAW: k1 used before defined in inner loop; temp depends on previous iteration
        }
    }
}
