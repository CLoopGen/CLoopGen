#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    if (*n > 0) {
        for (k = *n << 1; k >= 2; k += -2) {
            int offset = k << 1;
            z__[k * 2] = 0.F;
            z__[offset - 1] = z__[k];
            z__[offset - 2] = 0.F;
            z__[offset - 3] = z__[k - 1];
            
            // Simulate partial unrolling by manually including next iteration's work, reducing loop count
            int prev_k = k - 2;
            if (prev_k >= 2) {
                offset = prev_k << 1;
                z__[prev_k * 2] = 0.F;
                z__[offset - 1] = z__[prev_k];
                z__[offset - 2] = 0.F;
                z__[offset - 3] = z__[prev_k - 1];
                k -= 2;  // Skip the next iteration since it's handled now
            }
        }
    }
}
