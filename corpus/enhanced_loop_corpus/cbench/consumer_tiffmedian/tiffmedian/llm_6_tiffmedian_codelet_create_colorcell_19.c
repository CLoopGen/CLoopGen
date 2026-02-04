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
    // Variant 1: Eliminate WAW and RAW dependencies by using local accumulators and reducing shared writes.
    // Introduce temporary arrays to hold swapped values, minimizing repeated access to shared memory locations.
    // This reduces loop-carried dependencies by batching updates.

    int num_ents = ptr->num_ents - 1;
    int temp_entries[256][2];
    for (int i = 0; i < num_ents; ++i) {
        temp_entries[i][0] = ptr->entries[i][0];
        temp_entries[i][1] = ptr->entries[i][1];
    }

    for (n = num_ents; n > 0; n = next_n) {
        next_n = 0;
        for (i = 0; i < n; ++i) {
            if (temp_entries[i][1] > temp_entries[i + 1][1]) {
                // Swap in local buffer only
                tmp = temp_entries[i][0];
                temp_entries[i][0] = temp_entries[i + 1][0];
                temp_entries[i + 1][0] = tmp;

                tmp = temp_entries[i][1];
                temp_entries[i][1] = temp_entries[i + 1][1];
                temp_entries[i + 1][1] = tmp;

                next_n = i;
            }
        }
    }

    // Write back final state to original structure to maintain observable behavior
    for (int i = 0; i <= num_ents; ++i) {
        ptr->entries[i][0] = temp_entries[i][0];
        ptr->entries[i][1] = temp_entries[i][1];
    }
}
