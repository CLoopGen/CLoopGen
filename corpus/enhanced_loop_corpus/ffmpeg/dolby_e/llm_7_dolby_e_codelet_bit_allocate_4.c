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
    if (nb_exponent > 0) {
        msk_val[0] = (msk_val[0] > hearing_thresh[0]) ? msk_val[0] : hearing_thresh[0];
        for (i = 1; i < nb_exponent; i++) {
            int prev_val = msk_val[i-1]; // Introduce artificial loop-carried dependency (RAW)
            msk_val[i] = ((msk_val[i] + prev_val) > hearing_thresh[i]) ? (msk_val[i] + prev_val) : hearing_thresh[i];
        }
    }
}
