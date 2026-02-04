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
    uint32_t temp;
    for (k = 2; k < opt_order; k++) {
        temp = (1U << 14);
        quant_cof[k] = (quant_cof[k] * temp) + (add_base << 13);
    }
}
