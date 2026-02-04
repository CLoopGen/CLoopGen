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
for (k = 0; k < product_1; k++) {
    for (k1 = 1; k1 < q + 1; k1 <<= 1) {
        volatile size_t acc = 0;
        acc += k % (k1 + 1);
        acc += (k + k1) * 2;
    }
}
}
