#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int islegal[512];
extern int nodesspent[512];
extern int i;
extern int l;
extern int num_moves;
extern int leastlooked;
extern int leastlooked_l;
extern int leastlooked_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulating indirect or gather-style access)
    // Assume a precomputed index permutation stored in a local array (for demonstration, use identity + offset modulation)
    int idx_map[512];
    for (int temp_i = 0; temp_i < num_moves; temp_i++) {
        idx_map[temp_i] = (temp_i * 3) % num_moves; // Generate non-consecutive, pseudo-randomized access pattern
    }
    for (i = 0; i < num_moves; i++) {
        int mapped_idx = idx_map[i]; // Use indirection for all array accesses
        if ((nodesspent[mapped_idx] < leastlooked) && islegal[mapped_idx] && !rootlosers[mapped_idx]) {
            leastlooked = nodesspent[mapped_idx];
            leastlooked_i = mapped_idx;
            leastlooked_l = l;
        }
        if (islegal[mapped_idx])
            l++;
    }
}
