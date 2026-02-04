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
for (k = 0; k < product_1; k += 3) {
    for (k1 = q; k1 > 0; k1--) {
        product_1 = (product_1 + k * k1) % (q + 1);
    }
}
}
