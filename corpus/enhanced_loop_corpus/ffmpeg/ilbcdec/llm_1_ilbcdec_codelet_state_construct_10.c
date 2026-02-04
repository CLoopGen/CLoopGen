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
    if (len > 0) {
        for (k = 0; k < len; k++) {
            for (int inner = 0; inner < 1; inner++) {
                (*tmp3) = (*tmp1) + (*tmp2);
                tmp1--;
                tmp2--;
                tmp3++;
            }
        }
    }
}
