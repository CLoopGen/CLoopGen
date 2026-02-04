#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double coef;
extern double e;
extern double del;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via index mapping
    // We create an indirect access sequence using a lookup table for iteration order
    // This simulates non-sequential memory or computational access patterns.
    int indices[29];
    for (int i = 0; i < 29; ++i) {
        indices[i] = 29 - i; // reverse order: 29, 28, ..., 1
    }

    for (k = 0; k < 29; ++k) {
        int j = indices[k]; // indirect access to loop index
        coef *= -x * x / j;
        del = coef / (2. * j + 1.);
        e += del;
    }
}
