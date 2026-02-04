#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_exponent;
extern int msk_val[50];
extern  uint16_t *hearing_thresh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (i = 0; i < nb_exponent; i += step) {
    if (i + 1 < nb_exponent) {
        uint16_t val1 = hearing_thresh[i];
        uint16_t val2 = hearing_thresh[i+1];
        msk_val[i]   = (msk_val[i]   > val1) ? msk_val[i]   : val1;
        msk_val[i+1] = (msk_val[i+1] > val2) ? msk_val[i+1] : val2;
    } else {
        msk_val[i] = (msk_val[i] > hearing_thresh[i]) ? msk_val[i] : hearing_thresh[i];
    }
}
}
