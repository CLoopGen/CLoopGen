#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using index remapping
    // Access elements in reverse order (indirect pattern via reversed indexing)
    for (i = 0; i < ni; ++i) {
        int idx = ni - 1 - i; // Reverse mapping
        left[idx] = q[idx];
    }
}
