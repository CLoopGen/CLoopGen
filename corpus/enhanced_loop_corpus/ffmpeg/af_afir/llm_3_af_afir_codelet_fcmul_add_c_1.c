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
    // Variant 2: Strided memory access with increased stride
    // Access every second complex element (stride of 4 in float array) to simulate reduced reuse or subsampling
    // This changes temporal access pattern and may reduce cache efficiency

    const ptrdiff_t stride = 2;
    for (n = 0; n < len; n += stride) {
        if (n + stride > len) break; // Prevent out-of-bounds
        const float cre0 = c[2 * n];
        const float cim0 = c[2 * n + 1];
        const float tre0 = t[2 * n];
        const float tim0 = t[2 * n + 1];
        sum[2 * n] += tre0 * cre0 - tim0 * cim0;
        sum[2 * n + 1] += tre0 * cim0 + tim0 * cre0;

        const float cre1 = c[2 * (n + 1)];
        const float cim1 = c[2 * (n + 1) + 1];
        const float tre1 = t[2 * (n + 1)];
        const float tim1 = t[2 * (n + 1) + 1];
        sum[2 * (n + 1)] += tre1 * cre1 - tim1 * cim1;
        sum[2 * (n + 1) + 1] += tre1 * cim1 + tim1 * cre1;
    }
}
