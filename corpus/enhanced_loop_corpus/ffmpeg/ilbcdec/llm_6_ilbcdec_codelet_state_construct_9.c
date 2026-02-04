#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *synt_denum;
extern int k;
extern int16_t numerator[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[11];
    for (k = 0; k < 10 + 1; k++) {
        temp[k] = synt_denum[10 - k];
    }
    for (k = 0; k < 10 + 1; k++) {
        numerator[k] = temp[k];
    }
}
