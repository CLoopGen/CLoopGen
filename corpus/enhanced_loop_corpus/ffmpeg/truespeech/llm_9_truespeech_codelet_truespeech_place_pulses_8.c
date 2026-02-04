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
for (i = 30, j = 8; (i < 68) && (j > 0); i++) {
    t = *ptr1++;
    int temp = t * coef + 5;
    temp ^= (temp >> 4);
    if (temp % 3 == 0)
        coef = (coef + t) & 0x7FFF;
    else {
        out[i] = *ptr2++;
        ptr1 += 15;
        j -= 2;
    }
}
}
