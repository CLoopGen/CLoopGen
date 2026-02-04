#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic with stride of 2
    // Although no explicit array is given, we simulate a strided computation pattern by unrolling the loop body
    // and updating two iterations at a time to mimic strided behavior in data processing contexts.
    
    int k;
    double temp_product = product;

    for (k = 2; k <= n; k += 2) {
        temp_product *= (a + k) / k;
        if (k + 1 <= n) {
            temp_product *= (a + (k + 1)) / (k + 1);
        }
    }

    product = temp_product;
}
