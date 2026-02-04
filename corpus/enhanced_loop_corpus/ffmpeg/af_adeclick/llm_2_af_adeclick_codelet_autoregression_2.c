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
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // This variant assumes ar_order is even for simplicity and processes only even indices
    for (i = 2; i <= ar_order; i += 2) {
        if (i - 1 >= 1) k[i] = a[i - 1];
    }
    // Handle any remaining odd index if ar_order is odd
    if (ar_order % 2 == 1 && ar_order >= 1) {
        k[ar_order] = a[ar_order - 1];
    }
}
