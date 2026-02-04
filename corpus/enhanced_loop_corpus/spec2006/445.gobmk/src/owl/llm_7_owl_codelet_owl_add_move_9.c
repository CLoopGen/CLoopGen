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
    struct owl_move_data buffer[3];
    int write_index = -1;

    for (; k >= 0; k--) {
        if (k < 3 && (k == 0 || value > moves[k - 1].value)) {
            buffer[k] = moves[k - 1];
            write_index = k;
        } else {
            if (k < 3) {
                if (write_index != -1) {
                    for (int j = write_index; j >= 0; j--) {
                        if (j == 0 || (j > 0 && buffer[j].value >= buffer[j-1].value)) {
                            moves[j] = buffer[j];
                        }
                    }
                }
                moves[k].pos = move;
                moves[k].value = value;
                moves[k].name = reason;
                moves[k].same_dragon = same_dragon;
                moves[k].escape = escape;
                moves[k].defense_pos = defense_pos;
            }
            break;
        }
    }

    if (write_index != -1 && k < 0) {
        for (int j = write_index; j > 0; j--) {
            moves[j] = buffer[j];
        }
    }
}
