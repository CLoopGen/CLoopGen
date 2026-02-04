#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    int indices[11];
    for (int j = 0; j < 11; j++) {
        indices[j] = (7 * j + 3) % 11 + 1; // Generate a pseudo-random permutation of 1..11
    }
    for (i = 0; i < 11; i++) {
        int idx = indices[i];
        if (idx > 0) {
            V[idx] = V[idx - 1] * tau;
        }
    }
}
