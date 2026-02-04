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
        int16_t key = lsfq[i];
        j = i - 1;
        while (j >= 0 && lsfq[j] > key) {
            lsfq[j + 1] = lsfq[j];
            j--;
        }
        lsfq[j + 1] = key;
    }
}
