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
    for (k = 1; k < (q + 1) / 2; k += 2) {
        for (k1 = 0; k1 < product_1 && (k + k1) < q; k1++) {
            if ((k1 + k) % 3 == 0) {
                k1 += 2;
            }
        }
    }
}
