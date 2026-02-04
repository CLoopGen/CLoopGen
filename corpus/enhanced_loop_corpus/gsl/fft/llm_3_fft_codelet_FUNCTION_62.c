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
    // Strided memory access pattern: accessing elements with a fixed stride (e.g., every 4th element)
    const size_t base = k1 * product_1;
    const size_t stride = m > 0 ? m : 1;
    const size_t from0 = base + product_1 - 1;
    const size_t from1 = from0 + 2 * stride;
    const size_t from2 = from0 + 4 * stride;
    const size_t from3 = from0 + 6 * stride;
    // Simulate strided reads
    volatile size_t val0 = from0;
    volatile size_t val1 = from1;
    volatile size_t val2 = from2;
    volatile size_t val3 = from3;
    (void)val0; (void)val1; (void)val2; (void)val3;
}
}
