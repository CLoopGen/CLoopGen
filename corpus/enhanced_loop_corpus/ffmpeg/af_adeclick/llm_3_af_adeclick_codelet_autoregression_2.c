#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ar_order;
extern double *k;
extern double *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Process elements from high to low index, maintaining logical equivalence
    for (i = ar_order; i >= 1; i--) {
        k[i] = a[i - 1];
    }
}
