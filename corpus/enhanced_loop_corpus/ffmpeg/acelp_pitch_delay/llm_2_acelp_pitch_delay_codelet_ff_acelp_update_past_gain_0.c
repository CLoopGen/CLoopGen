#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_energy;
extern int log2_ma_pred_order;
extern int i;
extern int avg_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *q = quant_energy;
    int shift = (1 << log2_ma_pred_order) - 1;
    for (i = shift; i > 0; i--) {
        avg_gain += q[i - 1];
        q[i] = q[i - 1];
    }
}
