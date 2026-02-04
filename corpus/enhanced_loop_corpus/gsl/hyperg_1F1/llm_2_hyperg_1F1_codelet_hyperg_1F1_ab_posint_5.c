#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int b;
extern  double x;
extern int a0;
extern int n;
extern double Ma0np1;
extern double Ma0n;
extern double Ma0nm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern
    // Simulate strided memory traversal by modifying index update (stride of 2, descending)
    int stride = 2;
    for (n = a0 - 1; n > b; n -= stride) {
        if (n - 1 <= b) break; // Ensure we don't violate loop bounds due to stride
        Ma0nm1 = (-n * (1 - n - x) * Ma0n - x * (n - a0) * Ma0np1) / (n * (n - 1.));
        Ma0np1 = Ma0n;
        Ma0n = Ma0nm1;
    }
}
