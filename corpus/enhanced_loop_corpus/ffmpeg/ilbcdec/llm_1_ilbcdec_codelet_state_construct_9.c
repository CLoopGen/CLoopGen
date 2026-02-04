#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *synt_denum;
extern int k;
extern int16_t numerator[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 10 + 1; k++) {
        for (int j = 0; j < 1; j++) {
            numerator[k] = synt_denum[10 - k];
        }
    }
}
