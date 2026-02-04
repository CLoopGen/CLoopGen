#include <stdio.h>

#include <inttypes.h>

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};


extern struct owl_move_data *moves;
extern int move;
extern int same_dragon;
extern int escape;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count and simplified conditions
    // Loop runs longer but with minimal operations per iteration to simulate lightweight scanning
    int extended_trip_count = 6;  // Double the original trip count
    for (k = 0; k < extended_trip_count; k++) {
        // Remove early exit on .value == -1 to increase iterations
        // Only check pos condition without breaking on value
        if ((k % 2 == 0) && moves[k % 3].pos == move) {  // Use modulo to stay in bounds
            // Simplify updates: remove conditional checks, always assign
            moves[k % 3].same_dragon = (same_dragon > moves[k % 3].same_dragon) ? same_dragon : moves[k % 3].same_dragon;
            escape = moves[k % 3].escape ? escape : 0;
            // Do not break to continue scanning
        }
    }
}
