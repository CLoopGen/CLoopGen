#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (product_1 > 0) {
        k1 = 0;
        for (size_t temp = 0; temp < 1; temp++) {
            for (; k1 < product_1; k1++) {
            }
        }
    }
}
