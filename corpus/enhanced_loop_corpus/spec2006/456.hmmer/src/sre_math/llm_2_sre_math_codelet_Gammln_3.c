#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, with wrap-around handling)
    // We simulate strided access by stepping by 2 indices, but since we need to cover all elements,
    // we split the loop into two passes: first odd indices, then even indices.
    int stride = 2;
    for (i = 10; i >= 1; i -= stride) {
        value += cof[i] / tmp;
        tmp -= 1.;
        if (i - 1 >= 0) {
            value += cof[i-1] / tmp;
            tmp -= 1.;
        }
    }
}
