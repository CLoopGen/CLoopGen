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
    for (k = 2; k < opt_order; k += 2) {
        if (k + 1 < opt_order) {
            quant_cof[k] = (quant_cof[k] * (1U << 14)) + (add_base << 13);
            quant_cof[k + 1] = (quant_cof[k + 1] * (1U << 14)) + (add_base << 13);
        } else {
            quant_cof[k] = (quant_cof[k] * (1U << 14)) + (add_base << 13);
        }
    }
}
