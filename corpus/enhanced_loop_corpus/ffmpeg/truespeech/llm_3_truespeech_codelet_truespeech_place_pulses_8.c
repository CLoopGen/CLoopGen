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
for (i = 30 , j = 4; (i < 60) && (j > 0); i += 2) {  // Strided iteration (step by 2)
    t = *(ptr1 + (i % 15));  // Indirect and cyclic access pattern into ptr1 using modulo
    if (coef >= t)
        coef -= t;
    else {
        out[i] = *(ptr2 + (j - 1) * 2);  // Strided write with fixed stride
        ptr1 += 30;
        j--;
    }
}
}
