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
    for (n = 0; n < len && n < 64; n++) {
        const float cre = c[2 * n];
        const float cim = c[2 * n + 1];
        const float tre = t[2 * n];
        const float tim = t[2 * n + 1];
        float real_part = tre * cre - tim * cim;
        float imag_part = tre * cim + tim * cre;
        sum[2 * n] += real_part;
        sum[2 * n + 1] += imag_part;

        // Additional computational work to increase arithmetic intensity
        sum[2 * n] = (sum[2 * n] * sum[2 * n] + sum[2 * n + 1] * sum[2 * n + 1]) * 0.5f;
        sum[2 * n + 1] = (sum[2 * n] * sum[2 * n + 1]) * 2.0f;
    }
}
