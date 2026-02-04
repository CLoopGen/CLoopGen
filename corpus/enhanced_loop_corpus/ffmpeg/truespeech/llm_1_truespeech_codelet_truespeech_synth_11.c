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
    for (k = 0; k < 8; k++) {
        sum += ptr0[k] * t[k];
        if (k == 7) {
            out[i] = out[i] + ((-sum) >> 12);
            for (int j = 7; j > 0; j--) {
                ptr0[j] = ptr0[j - 1];
            }
            ptr0[0] = out[i];
        }
    }
}
}
