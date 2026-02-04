#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern int len;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect access by reversing the order of processing: from n2-1 down to 0
    for (i = n2 - 1; i >= 0; i--) {
        int idx = i;  // Logical index remains same, but traversal is reversed
        w = c - idx - 1.;
        w = 1. - (w * w);
        w_data[idx] = data[idx] * w;
        w_data[len - 1 - idx] = data[len - 1 - idx] * w;
    }
}
