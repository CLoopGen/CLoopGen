#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *synt_denum;
extern int k;
extern int16_t numerator[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    numerator[0] = synt_denum[10];
    for (k = 1; k < 10 + 1; k++) {
        numerator[k] = numerator[k - 1] + synt_denum[10 - k] - synt_denum[11 - k];
    }
}
