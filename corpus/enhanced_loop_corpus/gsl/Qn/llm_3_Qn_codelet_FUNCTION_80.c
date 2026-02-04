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
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary index array to reverse the order of access
    // This changes spatial locality and may affect cache behavior

    // Simulate indirect access by iterating backwards (reverse traversal)
    // Equivalent to accessing through an index map: idx[i] = ni - 1 - i
    for (i = ni - 1; i >= 0; --i) {
        int idx = ni - 1 - i; // Remapped index: access from end to start
        left[idx] = ni - idx + 1;
        right[idx] = (idx <= h) ? ni : ni - (idx - h);
    }
}
