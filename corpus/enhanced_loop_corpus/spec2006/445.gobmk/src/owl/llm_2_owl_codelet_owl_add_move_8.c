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
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of breaking early on moves[k], we traverse consecutively and use a flag to simulate break logic.
    int found = 0;
    for (k = 0; k < 3 && !found; k++) {
        if (moves[k].value == -1) {
            found = 1;
        } else if (moves[k].pos == move) {
            if (same_dragon > moves[k].same_dragon)
                moves[k].same_dragon = same_dragon;
            if (!moves[k].escape)
                escape = 0;
            found = 1;
        }
    }
}
