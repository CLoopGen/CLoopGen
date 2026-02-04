#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern size_t q;
extern size_t m;
extern size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k1 = 0; k1 < product_1; k1++) {
    const size_t from0 = 2 * k1 * q + q - 1;
    const size_t to0 = k1 * q + q - 1;
    const size_t to1 = to0 + m;
    // Introduce a loop-carried dependency by making current iteration depend on previous
    if (k1 > 0) {
        k1 += (to1 % 3); // Artificial RAW dependency with side effect on loop index
    }
}
}
