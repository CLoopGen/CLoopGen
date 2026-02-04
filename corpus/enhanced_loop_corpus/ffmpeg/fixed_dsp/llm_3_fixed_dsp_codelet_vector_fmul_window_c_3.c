#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src0;
extern  int32_t *src1;
extern  int32_t *win;
extern int len;
extern int32_t s0;
extern int32_t s1;
extern int32_t wi;
extern int32_t wj;
extern int32_t i;
extern int32_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with increasing step (stride = 2)
    // Access every second element in a symmetric fashion to simulate strided pattern
    // This changes access pattern to non-unit stride while maintaining symmetry
    int stride = 2;
    int count = (len + stride - 1) / stride;  // Number of iterations for strided access

    for (int k = 0; k < count; k++) {
        i = -len + k * stride;
        j = len - 1 - k * stride;

        if (i >= 0) break;  // Safety bound check since i must be < 0

        s0 = src0[i];
        s1 = src1[j];
        wi = win[i];
        wj = win[j];

        dst[i] = ((int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824) >> 31;
        dst[j] = ((int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824) >> 31;
    }
}
