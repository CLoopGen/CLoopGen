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
    for (i = 0; i < lp_order; i++) {
        for (j = 0; j < lp_order - i - 1; j++) {
            if (lsfq[j] > lsfq[j + 1]) {
                int16_t temp = lsfq[j];
                lsfq[j] = lsfq[j + 1];
                lsfq[j + 1] = temp;
            }
        }
    }
}
