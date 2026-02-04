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


extern struct owl_move_data moves[3];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency
    // by making each iteration depend on the completion of the previous one
    // through a dummy control variable that enforces sequential write order.
    int prev_written = 1;
    for (k = 0; k < 3; k++) {
        if (prev_written) {
            moves[k].pos = 0;
            moves[k].value = -1;
            moves[k].name = ((void *)0);
            moves[k].same_dragon = 2;
            moves[k].escape = 0;
            prev_written = 1; // Simulate enforced write ordering (WAW dependency)
        }
    }
}
