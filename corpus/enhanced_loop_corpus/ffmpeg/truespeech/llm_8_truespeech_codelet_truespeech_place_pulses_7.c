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
for (i = 0 , j = 3; (i < 60) && (j > 0); i += 2) {
    t = *ptr1++;
    t += *ptr1++; // Increased arithmetic intensity
    if (coef >= t)
        coef -= t;
    else {
        out[i] = *ptr2++;
        out[i+1] = *ptr2++; // Write two elements to increase data throughput
        ptr1 += 60; // Larger skip in ptr1
        j--;
    }
}
}
