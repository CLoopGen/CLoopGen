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
    for (i = 1; i < lp_order; i++) {
        int temp_val = lsfq[i];
        j = i - 1;
        for (; j >= 0; j--) {
            if (lsfq[j] <= temp_val) goto insert;
            lsfq[j + 1] = lsfq[j];
        }
        insert:
        lsfq[j + 1] = temp_val;
    }
}
