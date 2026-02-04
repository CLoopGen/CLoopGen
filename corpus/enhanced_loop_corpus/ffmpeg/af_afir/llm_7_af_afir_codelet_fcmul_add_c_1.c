#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sum;
extern  float *t;
extern  float *c;
extern ptrdiff_t len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < len; n++) {
        const float cre = c[2 * n];
        const float cim = c[2 * n + 1];
        const float tre = t[2 * n];
        const float tim = t[2 * n + 1];
        float result_re = tre * cre - tim * cim;
        float result_im = tre * cim + tim * cre;
        sum[2 * n] = sum[2 * n] + result_re;
        sum[2 * n + 1] = sum[2 * n + 1] + result_im;
    }
    // Introduce artificial loop-carried dependency via reuse of 'n' in a final update
    if (n > 0) {
        sum[0] += sum[2 * (n - 1)];
    }
}
