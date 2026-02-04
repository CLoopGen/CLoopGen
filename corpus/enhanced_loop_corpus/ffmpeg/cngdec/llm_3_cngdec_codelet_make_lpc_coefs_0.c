#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *refl;
extern int order;
extern float *next;
extern float *cur;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern with step of 2 (unrolled-like behavior), handling odd/even indices
    for (m = 0; m < order; m++) {
        next[m] = refl[m];
        // Process even indices first, then odd, to create strided access
        int i_even = 0;
        for (; i_even + 1 <= m; i_even += 2) {
            next[i_even] = cur[i_even] + refl[m] * cur[m - i_even - 1];
        }
        int i_odd = 1;
        for (; i_odd + 1 <= m; i_odd += 2) {
            next[i_odd] = cur[i_odd] + refl[m] * cur[m - i_odd - 1];
        }
        // Finalize pointer swap without do-while
        float *tmp = cur;
        cur = next;
        next = tmp;
    }
}
