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
for (i = 0; i < 30; i++) {
    int sum1 = 0, sum2 = 0;
    for (k = 0; k < 8; k += 2) {
        sum1 += ptr0[k] * t[k];
        if (k + 1 < 8)
            sum2 += ptr0[k + 1] * t[k + 1];
    }
    int total_sum = sum1 + sum2;
    for (k = 7; k > 1; k--)
        ptr0[k] = ptr0[k - 2];
    ptr0[1] = ptr0[0];
    ptr0[0] = out[i];
    out[i] += (-total_sum) >> 12;
}
}
