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
    int skip_update = 0;
    for (i = 0; i < nb_exponent; i++) {
        skip_update = (msk_val[i] > hearing_thresh[i]);
        if (!skip_update) {
            msk_val[i] = hearing_thresh[i];
        }
    }
}
