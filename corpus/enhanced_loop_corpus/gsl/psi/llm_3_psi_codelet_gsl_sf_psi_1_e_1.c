#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access pattern via index remapping (e.g., reverse order traversal)
    // We create a local index mapping that accesses loop iterations in reverse
    // This changes memory access pattern predictability, simulating indirect access behavior
    for (int i = 0; i < M; ++i) {
        m = M - 1 - i;  // Reverse mapping: indirect-like access
        sum += 1. / ((x + m) * (x + m));
    }
}
