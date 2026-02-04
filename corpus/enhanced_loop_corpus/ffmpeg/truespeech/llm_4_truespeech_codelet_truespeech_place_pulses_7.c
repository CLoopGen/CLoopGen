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
for (i = 0 , j = 3; (i < 30) && (j > 0); i++) {
    t = *ptr1++;
    coef -= t;
    out[i] = *ptr2++;
    ptr1 += 30;
    j--;
}
}
