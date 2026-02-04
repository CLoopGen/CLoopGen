#include <stdio.h>

#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};


extern struct aa_move attacks[361];
extern int target;
extern int k;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using a fixed index map (simulating indirect pattern)
    const int index_map[4] = {3, 1, 2, 0}; // Reordered indices to simulate indirect access
    int r;
    for (r = 0; r < 4; r++) {
        int idx = index_map[r];
        if (attacks[k].target[idx] == target || attacks[k].target[idx] == 0) {
            r = idx; // Preserve logical r as the actual target index
            break;
        }
    }
}
