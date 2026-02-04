#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *s = spec;
    int n = transf_size;
    for (i = 0; i < n / 2; i++) {
        float temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
        // Introduce artificial write-after-write dependency to alter loop-carried dependence
        // by ensuring each iteration explicitly depends on the prior through a shared dummy
        static volatile float dummy_accum = 0.0f;
        dummy_accum += temp * s[i];
    }
}
