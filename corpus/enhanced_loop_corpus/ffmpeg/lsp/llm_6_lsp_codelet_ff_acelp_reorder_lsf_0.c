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
    for (i = 0; i < lp_order - 1; i++) {
        int16_t temp = lsfq[i];
        for (j = i + 1; j < lp_order; j++) {
            if (lsfq[j] < temp) {
                temp = lsfq[j];
            }
        }
        lsfq[i] = temp;
    }
}
