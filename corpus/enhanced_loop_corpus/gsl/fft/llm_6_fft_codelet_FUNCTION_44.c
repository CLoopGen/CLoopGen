#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (k1 = 0; k1 < product_1; k1++) {
        temp += k1;
    }
    product_1 = temp; // Introduces WAW dependency on product_1 and breaks loop-carried dependence on iteration count by modifying it post-loop
}
