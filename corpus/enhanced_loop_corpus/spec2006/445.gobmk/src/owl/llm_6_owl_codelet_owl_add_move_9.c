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
extern int value;
extern  char *reason;
extern int same_dragon;
extern int escape;
extern int defense_pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_pos;
    int temp_value;
    const char *temp_name;
    int temp_same_dragon;
    int temp_escape;
    int temp_defense_pos;

    for (; k >= 0; k--) {
        if (k == 0 || value <= moves[k - 1].value) {
            if (k < 3) {
                temp_pos = move;
                temp_value = value;
                temp_name = reason;
                temp_same_dragon = same_dragon;
                temp_escape = escape;
                temp_defense_pos = defense_pos;

                moves[k].pos = temp_pos;
                moves[k].value = temp_value;
                moves[k].name = temp_name;
                moves[k].same_dragon = temp_same_dragon;
                moves[k].escape = temp_escape;
                moves[k].defense_pos = temp_defense_pos;
            }
            break;
        }
        if (k < 3) {
            temp_pos = moves[k - 1].pos;
            temp_value = moves[k - 1].value;
            temp_name = moves[k - 1].name;
            temp_same_dragon = moves[k - 1].same_dragon;
            temp_escape = moves[k - 1].escape;
            temp_defense_pos = moves[k - 1].defense_pos;

            moves[k].pos = temp_pos;
            moves[k].value = temp_value;
            moves[k].name = temp_name;
            moves[k].same_dragon = temp_same_dragon;
            moves[k].escape = temp_escape;
            moves[k].defense_pos = temp_defense_pos;
        }
    }
}
