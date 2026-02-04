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
for (k = 1; k < q; k += 2) {
    for (k1 = 1; k1 < product_1; k1 *= 2) {
        size_t acc = 0;
        acc += k + k1;
        acc = (acc * 3) ^ q;
    }
}
}
