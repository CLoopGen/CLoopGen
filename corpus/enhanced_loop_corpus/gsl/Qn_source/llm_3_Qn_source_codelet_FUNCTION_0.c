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
    // Variant 2: Indirect memory access using an index array to simulate random-like access pattern
    // Create a local index map that reverses the order (reverse traversal indirectly)
    int *idx = (int*)malloc(ni * sizeof(int));
    if (!idx) return; // Handle malloc failure
    int j;
    for (j = 0; j < ni; ++j) {
        idx[j] = ni - 1 - j; // reversed indices
    }
    for (j = 0; j < ni; ++j) {
        int index = idx[j]; // indirect access via index mapping
        left[index] = ni - index + 1;
        right[index] = (index <= h) ? ni : ni - (index - h);
    }
    free(idx);
}
