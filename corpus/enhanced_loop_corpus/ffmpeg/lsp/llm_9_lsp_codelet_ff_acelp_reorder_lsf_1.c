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
    for (i = 0; i < lp_order; i += 2) {
        if (i + 1 < lp_order) {
            lsfq[i]     = (lsfq[i]     > lsfq_min) ? lsfq[i]     : lsfq_min;
            lsfq[i + 1] = (lsfq[i + 1] > lsfq_min) ? lsfq[i + 1] : lsfq_min;
            lsfq_min = (lsfq[i] > lsfq[i + 1] ? lsfq[i] : lsfq[i + 1]) + lsfq_min_distance;
        } else {
            lsfq[i] = (lsfq[i] > lsfq_min) ? lsfq[i] : lsfq_min;
            lsfq_min = lsfq[i] + lsfq_min_distance;
        }
    }
}
