#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t len;
extern int k;
extern int16_t *tmp1;
extern int16_t *tmp2;
extern int16_t *tmp3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < len; k++) {
        if (tmp1 != NULL && tmp2 != NULL && tmp3 != NULL) {
            (*tmp3) = (*tmp1) + (*tmp2);
        }
        tmp1--;
        tmp2--;
        tmp3++;
    }
}
