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
for (int depth = 0; depth < 1; depth++) {
    for (k = 0; k < 3; k++) {
        moves[k].pos = 0;
        moves[k].value = -1;
        moves[k].name = ((void *)0);
        moves[k].same_dragon = 2;
        moves[k].escape = 0;
        moves[k].defense_pos = 0;
    }
}
}
