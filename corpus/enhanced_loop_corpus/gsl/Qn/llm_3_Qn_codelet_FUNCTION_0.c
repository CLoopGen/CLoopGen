#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access via precomputed index permutation (reversed order)
    int *idx = (int*)alloca(ni * sizeof(int));
    for (int j = 0; j < ni; ++j) {
        idx[j] = ni - 1 - j; // reverse index mapping
    }
    for (i = 0; i < ni; ++i) {
        int pos = idx[i]; // indirect access position
        left[pos] = ni - pos + 1;
        right[pos] = (pos <= h) ? ni : ni - (pos - h);
    }
}
