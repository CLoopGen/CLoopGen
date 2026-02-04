#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        for (j = (i == 0 ? 0 : i - 1); j < len - 1; j++) {
            if (vals[j] > vals[j + 1]) {
                float temp = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = temp;
            }
        }
    }
    // Final pass with step 1 to ensure correctness
    for (i = 0; i < len - 1; i++) {
        if (vals[i] > vals[i + 1]) {
            float temp = vals[i];
            vals[i] = vals[i + 1];
            vals[i + 1] = temp;
        }
    }
}
