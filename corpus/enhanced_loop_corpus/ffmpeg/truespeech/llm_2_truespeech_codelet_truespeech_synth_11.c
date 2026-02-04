#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int i;
extern int k;
extern int t[8];
extern int16_t *ptr0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 60; i++) {
    int sum = 0;
    for (k = 0; k < 8; k += 2)
        sum += ptr0[k] * t[k];
    for (k = 1; k < 8; k += 2)
        sum += ptr0[k] * t[k];
    for (k = 7; k > 0; k--)
        ptr0[k] = ptr0[k - 1];
    ptr0[0] = out[i];
    out[i] += (-sum) >> 12;
}
}
