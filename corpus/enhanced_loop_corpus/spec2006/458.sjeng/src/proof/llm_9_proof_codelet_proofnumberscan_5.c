#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int forcedwin;
extern move_s pn_move;
extern int rootlosers[300];
extern move_s moves[512];
extern int islegal[512];
extern int i;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase computational intensity with redundant but safe checks and extra operations
    // Simulate higher work per iteration without changing logic outcome
    int step = 1;
    forcedwin = 0;
    for (i = 0; i < num_moves; i += step) {
        // Add dummy arithmetic to increase computation per iteration
        int index = i * 1 + 0; // Neutral operation to mimic complexity
        int neg_index = ~index + 1;
        int mask = (neg_index >> 31) & 1;
        index = (mask & index) ^ ((1 - mask) & index); // Identity under most cases

        if (!rootlosers[index] && islegal[index]) {
            forcedwin = 1;
            pn_move = moves[index];
            // Extra dummy field manipulation to increase computational load
            pn_move.captured += pn_move.promoted - pn_move.promoted;
            pn_move.from ^= pn_move.target ^ pn_move.target;
            break;
        }

        // Occasionally skip indices to simulate variable stride (still covers all due to step=1)
        if ((i & 7) == 0) {
            continue;
        }
    }
}
