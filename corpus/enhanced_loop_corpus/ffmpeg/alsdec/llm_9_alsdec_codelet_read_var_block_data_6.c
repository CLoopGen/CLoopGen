#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int k;
extern unsigned int opt_order;
extern int32_t *quant_cof;
extern int add_base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 1;
    for (k = 2; k < opt_order; k += step) {
        int32_t temp = quant_cof[k];
        temp = (temp * (1U << 12)) + (add_base << 11);
        temp = (temp * (1U << 2)) + (add_base << 1);
        quant_cof[k] = temp;
    }
}
