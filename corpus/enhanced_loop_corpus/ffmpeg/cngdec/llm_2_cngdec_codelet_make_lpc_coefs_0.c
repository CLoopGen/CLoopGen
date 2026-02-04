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
    // Variant 1: Consecutive memory access with reversed traversal and offset indexing
    for (m = 0; m < order; m++) {
        next[m] = refl[m];
        for (i = 0; i < m; i++) {
            int idx = m - i - 1;
            next[i] = cur[i] + refl[m] * cur[idx];
        }
        // Swap pointers using temporary without do-while
        float *temp = cur;
        cur = next;
        next = temp;
    }
}
