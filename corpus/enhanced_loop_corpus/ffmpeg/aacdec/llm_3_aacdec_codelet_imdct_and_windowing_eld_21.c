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
    // Variant 2: Strided memory access with increased stride to simulate non-unit jumps (stride of 2)
    // Access every second element, adjusting bounds accordingly to stay within limits
    int stride = 2;
    int limit = n2 / stride;

    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        out[n4 + idx] = ((buf[idx]) * (window[idx + n2 - n4])) +
                        ((-saved[n - 1 - idx]) * (window[idx + n2 + n - n4])) +
                        ((-saved[n + idx]) * (window[idx + n2 + 2 * n - n4])) +
                        ((saved[2 * n + n - 1 - idx]) * (window[idx + n2 + 3 * n - n4]));

        // Process next in-stride element if within bounds
        if (idx + 1 < n2) {
            out[n4 + idx + 1] = ((buf[idx + 1]) * (window[idx + 1 + n2 - n4])) +
                                ((-saved[n - 1 - (idx + 1)]) * (window[idx + 1 + n2 + n - n4])) +
                                ((-saved[n + idx + 1]) * (window[idx + 1 + n2 + 2 * n - n4])) +
                                ((saved[2 * n + n - 1 - (idx + 1)]) * (window[idx + 1 + n2 + 3 * n - n4]));
        }
    }
}
