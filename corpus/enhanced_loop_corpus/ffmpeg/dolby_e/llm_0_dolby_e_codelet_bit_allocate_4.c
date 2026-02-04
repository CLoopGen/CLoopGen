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
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < nb_exponent; i++)
            msk_val[i] = ((msk_val[i]) > (hearing_thresh[i]) ? (msk_val[i]) : (hearing_thresh[i]));
}
