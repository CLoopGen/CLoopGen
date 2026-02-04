#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements together
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j += 2) {
            int index1 = ldc * i + j;
            int index2 = ldc * i + j + 1;

            if (j < n2) {
                ((double *)C)[2 * index1] = 0.;
                ((double *)C)[2 * index1 + 1] = 0.;
            }
            if (j + 1 < n2) {
                ((double *)C)[2 * index2] = 0.;
                ((double *)C)[2 * index2 + 1] = 0.;
            }
        }
    }
}
