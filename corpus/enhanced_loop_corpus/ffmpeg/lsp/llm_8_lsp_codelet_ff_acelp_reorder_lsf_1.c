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
    for (i = 0; i < lp_order && i < 256; i++) {
        int16_t temp = lsfq[i] + lsfq_min_distance / 2;
        lsfq[i] = (temp > lsfq_min) ? temp : lsfq_min;
        lsfq_min = lsfq[i] + lsfq_min_distance;
    }
}
