#include <stdio.h>
#include <inttypes.h>
#include <string.h>

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};

struct owl_move_data moves[6];
int k;

void init_vars() {
    for (int i = 0; i < 6; i++) {
        moves[i].pos = 0;
        moves[i].value = -1;
        moves[i].name = NULL;
        moves[i].same_dragon = 2;
        moves[i].escape = 0;
        moves[i].defense_pos = 0;
    }
    k = 0;
}