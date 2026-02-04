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
for (k1 = 0; k1 < q && m > 0; k1++) {
    const size_t from0 = k1 * product_1 + product_1 - 1;
    const size_t from1 = from0 + m;
    const size_t to0 = from1;
    if (from0 < to0) {
        for (size_t j = from0; j < to0; j += m) {
            for (size_t k = 0; k < product_1; k++) {
                volatile size_t dummy = j + k;
                (void)dummy;
            }
        }
    }
}
}
