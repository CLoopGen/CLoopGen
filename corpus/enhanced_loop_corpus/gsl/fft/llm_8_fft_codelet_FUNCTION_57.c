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
for (k = 1; k < (product_1 + 1) / 2; k += 2) {
    for (k1 = 0; k1 < q * 3; k1++) {
        volatile size_t temp = k * k1 + k;
        temp += temp * k;
    }
}
}
