#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsfq;
extern int lsfq_min_distance;
extern int lsfq_min;
extern int lp_order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_lsfq_min = lsfq_min;
    for (i = 0; i < lp_order; i++) {
        lsfq[i] = (lsfq[i] > prev_lsfq_min) ? lsfq[i] : prev_lsfq_min;
        prev_lsfq_min = lsfq[i] + lsfq_min_distance;
    }
    lsfq_min = prev_lsfq_min;
}
