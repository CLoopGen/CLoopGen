#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via reverse order access)
    // Simulate indirect access by traversing in reverse, which changes access pattern
    for (int i = histosize - 1; i >= 0; i--) {
        historesult[i] = (float)h_offsets[i];
    }
}
