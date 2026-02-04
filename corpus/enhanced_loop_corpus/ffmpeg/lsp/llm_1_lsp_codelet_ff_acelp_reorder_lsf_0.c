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
        int temp_index = i;
        while (temp_index > 0 && lsfq[temp_index] < lsfq[temp_index - 1]) {
            int16_t SWAP_tmp = lsfq[temp_index];
            lsfq[temp_index] = lsfq[temp_index - 1];
            lsfq[temp_index - 1] = SWAP_tmp;
            temp_index--;
        }
    }
}
