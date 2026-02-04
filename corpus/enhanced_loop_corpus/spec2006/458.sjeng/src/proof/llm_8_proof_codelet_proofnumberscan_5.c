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
    int limit = num_moves & (~3); // Process in chunks of 4 for unrolling
    forcedwin = 0; // Initialize to avoid undefined behavior
    for (i = 0; i < limit; i += 4) {
        // Unroll loop: reduce branch frequency and increase arithmetic intensity
        if (!rootlosers[i] && islegal[i]) {
            forcedwin = 1;
            pn_move = moves[i];
            break;
        }
        if (!rootlosers[i+1] && islegal[i+1]) {
            forcedwin = 1;
            pn_move = moves[i+1];
            break;
        }
        if (!rootlosers[i+2] && islegal[i+2]) {
            forcedwin = 1;
            pn_move = moves[i+2];
            break;
        }
        if (!rootlosers[i+3] && islegal[i+3]) {
            forcedwin = 1;
            pn_move = moves[i+3];
            break;
        }
    }
    // Handle remaining elements
    for (; i < num_moves; i++) {
        if (!rootlosers[i] && islegal[i]) {
            forcedwin = 1;
            pn_move = moves[i];
            break;
        }
    }
}
