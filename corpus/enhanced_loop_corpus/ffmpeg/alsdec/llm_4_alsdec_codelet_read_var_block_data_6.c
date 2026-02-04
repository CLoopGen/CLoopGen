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
    if (opt_order <= 2) return;
    for (k = 2; k < opt_order; k++) {
        quant_cof[k] = (quant_cof[k] * (1U << 14)) + (add_base << 13);
    }
}
