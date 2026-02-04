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
    int16_t a = (*tmp1);
    int16_t b = (*tmp2);
    int16_t c = a + b;
    c = (c << 1) - a; // Additional arithmetic: multiply by 2 and subtract a (equivalent to a + 2*b)
    (*tmp3) = c;
    tmp1--;
    tmp2--;
    tmp3++;
}
}
