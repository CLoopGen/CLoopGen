#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < product_1; k1 += 2) {
        volatile size_t temp = k1 * k1 + 3;
        temp += temp * 2;
    }
}
