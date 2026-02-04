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
for (k = 0; k < 3; k++) {
    if (moves[k].value == -1)
        continue;
    if (moves[k].pos != move) {
        continue;
    }
    if (same_dragon > moves[k].same_dragon)
        moves[k].same_dragon = same_dragon;
    if (!moves[k].escape)
        escape = 0;
    break;
}
}
