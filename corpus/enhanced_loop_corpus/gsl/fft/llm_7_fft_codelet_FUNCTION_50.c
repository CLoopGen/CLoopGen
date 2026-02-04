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
size_t prev_from0 = 0;
for (k1 = 0; k1 < q; k1++) {
    const size_t from0 = k1 * product_1 + product_1 - 1;
    const size_t from1 = prev_from0 + m;
    const size_t to0 = from1 + from0;
    prev_from0 = from0;
}
}
