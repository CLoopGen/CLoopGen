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
    // Variant 2: Indirect memory access using an index remapping array
    // We simulate indirect access by defining a virtual index order based on reversal
    // This changes the access pattern to process elements from both ends inward
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create an indirect access pattern: [0, ni-1, 1, ni-2, 2, ni-3, ...]
    int front = 0, back = ni - 1;
    int toggle = 0;

    for (i = 0; i < ni; ++i) {
        if (toggle == 0 && front <= back) {
            index_map[i] = front++;
        } else if (toggle == 1 || front > back) {
            index_map[i] = back--;
        }
        toggle = 1 - toggle; // Alternate between front and back
    }

    // Traverse using the indirect index mapping
    for (i = 0; i < ni; ++i) {
        int idx = index_map[i];
        left[idx] = ni - idx + 1;
        right[idx] = (idx <= h) ? ni : ni - (idx - h);
    }

    free(index_map);
}
