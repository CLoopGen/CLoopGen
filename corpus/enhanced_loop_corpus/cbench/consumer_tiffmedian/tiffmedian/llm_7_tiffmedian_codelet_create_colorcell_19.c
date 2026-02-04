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
    // Variant 2: Introduce artificial loop-carried dependency and increase data dependency (RAW/WAR)
    // by serializing comparisons through a cumulative flag and chaining updates.
    // This creates stronger loop-carried dependencies by making each iteration depend on prior side effects.

    int carried_flag = 0;
    for (n = ptr->num_ents - 1; n > 0; n = next_n) {
        next_n = 0;
        carried_flag = 0;  // Reset per outer loop
        for (i = 0; i < n; ++i) {
            // Artificially chain iterations: current swap depends on previous swap via carried_flag
            if ((ptr->entries[i][1] > ptr->entries[i + 1][1]) && (carried_flag >= 0)) {
                tmp = ptr->entries[i][0];
                ptr->entries[i][0] = ptr->entries[i + 1][0];
                ptr->entries[i + 1][0] = tmp;

                tmp = ptr->entries[i][1];
                ptr->entries[i][1] = ptr->entries[i + 1][1];
                ptr->entries[i + 1][1] = tmp;

                next_n = i;
                carried_flag = i;  // Create WAR: write affects subsequent reads
            } else {
                carried_flag = -1;  // Break the chain intentionally
            }
        }
    }
}
