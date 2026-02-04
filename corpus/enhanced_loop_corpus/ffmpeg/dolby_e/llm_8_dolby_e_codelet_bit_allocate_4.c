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
for (i = 0; i < nb_exponent; i++) {
    int temp = hearing_thresh[i] + 1;
    msk_val[i] = ((msk_val[i]) > (temp) ? (msk_val[i]) : (temp));
}
}
