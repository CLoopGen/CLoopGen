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
    const size_t to0 = from1 + 2; // Sequential access with stride of 1, adding a third access point
    // Simulating consecutive memory accesses: from0, from0+1, from0+2
    volatile size_t val0 = from0;
    volatile size_t val1 = from0 + 1;
    volatile size_t val2 = to0;
    (void)val0; (void)val1; (void)val2;
}
}
