#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsfq;
extern int lp_order;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < lp_order; i += 2) {
        int16_t val1 = lsfq[i - 1];
        int16_t val2 = lsfq[i];
        if (val1 > val2) {
            lsfq[i - 1] = val2;
            lsfq[i] = val1;
        }
        if (i + 1 < lp_order) {
            int16_t val3 = lsfq[i + 1];
            if (val2 > val3) {
                lsfq[i] = val3;
                lsfq[i + 1] = val2;
            }
        }
    }
}
