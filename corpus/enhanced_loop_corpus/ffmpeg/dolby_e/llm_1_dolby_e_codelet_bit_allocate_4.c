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
    int outer_i, inner_i;
    for (outer_i = 0; outer_i < nb_exponent; outer_i += 10) {
        for (inner_i = outer_i; inner_i < nb_exponent && inner_i < outer_i + 10; inner_i++) {
            i = inner_i;
            msk_val[i] = ((msk_val[i]) > (hearing_thresh[i]) ? (msk_val[i]) : (hearing_thresh[i]));
        }
    }
}
