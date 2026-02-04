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
    // Variant 1: Strided memory access with stride of 2, unrolled loop by factor 2
    leastlooked_l = 0; // Reset l equivalent for correctness
    for (i = 0; i < num_moves; i += 2) {
        int indices[2] = {i, i + 1};
        for (int j = 0; j < 2; j++) {
            if (indices[j] >= num_moves) break;
            if ((nodesspent[indices[j]] < leastlooked) && islegal[indices[j]] && !rootlosers[indices[j]]) {
                leastlooked = nodesspent[indices[j]];
                leastlooked_i = indices[j];
                leastlooked_l = l;
            }
            if (islegal[indices[j]])
                l++;
        }
    }
}
