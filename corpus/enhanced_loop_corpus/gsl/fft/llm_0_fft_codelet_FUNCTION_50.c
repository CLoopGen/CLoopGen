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
    const size_t from0 = k1 * product_1 + product_1 - 1;
    const size_t from1 = from0 + m;
    const size_t to0 = from1;
    for (size_t i = from0; i < to0; i++) {
        // Dummy operation to give loop body meaning
        volatile size_t dummy = i;
        (void)dummy;
    }
}
}
