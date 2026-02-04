#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t m;
extern  size_t q;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k1 = 0; k1 < q; k1++) {
    const size_t index = (k1 * product_1) & (q - 1); // Strided and wrapped access pattern
    const size_t from0 = index * m + product_1 - 1;
    const size_t from1 = from0 + (m << 1); // Double step for strided access
    const size_t to0 = from0 ^ from1; // Indirect-like dependency via XOR instead of linear
    // Simulate indirect usage with data-dependent address (in practice, this could index an array)
    volatile size_t dummy = to0;
}
}
