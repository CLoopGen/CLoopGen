#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern modified to step by 2, processing two elements per iteration for better vectorization potential
    int i;
    for (i = n4; i < n2; i += 2) {
        if (i + 1 < n2) {
            // Process current and next element using strided access
            out[i - n4] = ((buf[n2 - 1 - i]) * (window[i - n4])) +
                          ((saved[i + n2]) * (window[i + n - n4])) +
                          ((-saved[n + n2 - 1 - i]) * (window[i + 2 * n - n4])) +
                          ((-saved[2 * n + n2 + i]) * (window[i + 3 * n - n4]));

            out[i + 1 - n4] = ((buf[n2 - 1 - (i + 1)]) * (window[i + 1 - n4])) +
                              ((saved[i + 1 + n2]) * (window[i + 1 + n - n4])) +
                              ((-saved[n + n2 - 1 - (i + 1)]) * (window[i + 1 + 2 * n - n4])) +
                              ((-saved[2 * n + n2 + (i + 1)]) * (window[i + 1 + 3 * n - n4]));
        } else {
            // Handle leftover element if n2 - n4 is odd
            out[i - n4] = ((buf[n2 - 1 - i]) * (window[i - n4])) +
                          ((saved[i + n2]) * (window[i + n - n4])) +
                          ((-saved[n + n2 - 1 - i]) * (window[i + 2 * n - n4])) +
                          ((-saved[2 * n + n2 + i]) * (window[i + 3 * n - n4]));
        }
    }
}
