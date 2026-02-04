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
    for (k = 0; k < q * 2; k++) {
        for (k1 = 1; k1 < product_1 + 1; k1 <<= 1) {
            if ((k % 3) == 0) {
                k1 += k % 5;
            }
        }
    }
}
