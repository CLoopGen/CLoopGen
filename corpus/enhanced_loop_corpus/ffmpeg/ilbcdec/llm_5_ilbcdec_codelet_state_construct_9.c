#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *synt_denum;
extern int k;
extern int16_t numerator[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 11; k++) {
        numerator[k] = (k < 5) ? synt_denum[10 - k] : synt_denum[0];
    }
}
