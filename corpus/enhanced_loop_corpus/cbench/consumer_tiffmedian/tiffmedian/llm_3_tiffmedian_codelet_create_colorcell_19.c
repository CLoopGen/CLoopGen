#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

extern int i;
extern C_cell *ptr;
extern int next_n;
extern int tmp;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (Index Array-Based) Memory Access Pattern
    // Introduce an index mapping array to access entries indirectly
    // Simulate sorting via indirection without changing the original array order directly
    // Use an auxiliary index array to represent logical ordering
    int index[256];
    for (i = 0; i < ptr->num_ents; ++i) {
        index[i] = i;
    }

    for (n = ptr->num_ents - 1; n > 0; n = next_n) {
        next_n = 0;
        for (i = 0; i < n; ++i) {
            int idx1 = index[i];
            int idx2 = index[i + 1];
            if (ptr->entries[idx1][1] > ptr->entries[idx2][1]) {
                // Swap indices based on key comparison
                tmp = index[i];
                index[i] = index[i + 1];
                index[i + 1] = tmp;
                next_n = i;
            }
        }
    }

    // Reorder the original array based on final index permutation
    C_cell temp_ptr = *ptr;
    for (i = 0; i < ptr->num_ents; ++i) {
        int src = index[i];
        ptr->entries[i][0] = temp_ptr.entries[src][0];
        ptr->entries[i][1] = temp_ptr.entries[src][1];
    }
}
