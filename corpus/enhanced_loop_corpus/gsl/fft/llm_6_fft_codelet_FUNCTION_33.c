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
    size_t temp = 0;
    for (k = 1; k < (q + 1) / 2; k++) {
        temp += k;  // Introduce WAW dependency on temp across iterations
        for (k1 = 0; k1 < product_1; k1++) {
            temp = temp + k * k1;  // RAW dependency: uses k and k1; loop-carried via temp
        }
    }
}
