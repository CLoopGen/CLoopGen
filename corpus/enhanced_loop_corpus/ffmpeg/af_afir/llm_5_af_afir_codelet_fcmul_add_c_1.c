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
        float temp_re = tre * cre - tim * cim;
        float temp_im = tre * cim + tim * cre;

        if (temp_re > 0.0f) {
            sum[2 * n] += temp_re;
        }
        if (temp_im < 0.0f) {
            sum[2 * n + 1] -= temp_im;
        } else {
            sum[2 * n + 1] += temp_im;
        }
    }
}
