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
    // Variant 2: Strided memory access - iterate over C array directly with stride of 2
    int total_elements = n1 * n2;
    for (int idx = 0; idx < total_elements; idx++) {
        int i = idx / n2;
        int j = idx % n2;
        int base_offset = 2 * (ldc * i + j);
        ((double *)C)[base_offset] = 0.;
        ((double *)C)[base_offset + 1] = 0.;
    }
}
