#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pb[];
extern int ph[51];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes even indices first, then odd if needed, but here we assume size is even (51 elements)
    // We split the loop into two sequential loops for stride-2 access to maintain coverage
    int i;
    for (i = 0; i <= 50; i += 2) {
        ph[i] = pb[i];
    }
    for (i = 1; i <= 50; i += 2) {
        ph[i] = pb[i];
    }
}
