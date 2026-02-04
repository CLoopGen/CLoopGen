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
    k = 0;
    for (; k < 8; k++) {
        sum += ptr0[k] * t[k];
    }
    k = 7;
    if (i % 2 == 0) {
        while (k > 0) {
            ptr0[k] = ptr0[k - 1];
            k--;
        }
    } else {
        for (; k > 0; k--) {
            ptr0[k] = ptr0[k - 1];
        }
    }
    ptr0[0] = out[i];
    out[i] += (-sum) >> 12;
}
}
