#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int i;
extern int j;
extern int t;
extern  int16_t *ptr1;
extern int16_t *ptr2;
extern int coef;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 30; i++) {
        if (j <= 0) break;
        t = *ptr1++;
        if (coef >= t)
            coef -= t;
        else {
            out[i] = *ptr2++;
            ptr1 += 30;
            j--;
        }
    }
}
