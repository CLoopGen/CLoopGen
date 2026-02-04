#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (simulating non-unit stride pattern)
    // Use a stride of 2 by skipping every other element, adjusting loop bound accordingly
    int stride = 2;
    int adjusted_n4 = n4 / stride;

    for (i = 0; i < adjusted_n4; i++) {
        int idx = i * stride;  // Strided index

        out[n2 + n4 + idx] = (int)(((int64_t)(buf[idx + n2]) * (window[idx + n - n4]) + 1073741824) >> 31) +
                             (int)(((int64_t)(-saved[n2 - 1 - idx]) * (window[idx + 2 * n - n4]) + 1073741824) >> 31) +
                             (int)(((int64_t)(-saved[n + n2 + idx]) * (window[idx + 3 * n - n4]) + 1073741824) >> 31);
    }

    // Handle remaining elements if n4 is not divisible by stride
    for (; i * stride < n4; i++) {
        int idx = i * stride;
        out[n2 + n4 + idx] = (int)(((int64_t)(buf[idx + n2]) * (window[idx + n - n4]) + 1073741824) >> 31) +
                             (int)(((int64_t)(-saved[n2 - 1 - idx]) * (window[idx + 2 * n - n4]) + 1073741824) >> 31) +
                             (int)(((int64_t)(-saved[n + n2 + idx]) * (window[idx + 3 * n - n4]) + 1073741824) >> 31);
    }
}
