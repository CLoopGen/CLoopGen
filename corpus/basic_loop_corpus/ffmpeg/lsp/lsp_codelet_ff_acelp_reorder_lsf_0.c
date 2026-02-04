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
for (i = 0; i < lp_order - 1; i++)
    for (j = i; j >= 0 && lsfq[j] > lsfq[j + 1]; j--)
        do {
            int16_t SWAP_tmp = lsfq[j + 1];
            lsfq[j + 1] = lsfq[j];
            lsfq[j] = SWAP_tmp;
        } while (0);

}
