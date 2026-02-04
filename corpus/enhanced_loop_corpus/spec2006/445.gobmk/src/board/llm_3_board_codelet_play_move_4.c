#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *color_src = move_history_color + number_collapsed_moves;
    int *pos_src = move_history_pos + number_collapsed_moves;
    int count = move_history_pointer - number_collapsed_moves;
    for (k = 0; k < count; k += 2) {
        move_history_color[k/2] = color_src[k];
        move_history_pos[k/2] = pos_src[k];
        if (k + 1 < count) {
            move_history_color[(k+1)/2] = color_src[k+1];
            move_history_pos[(k+1)/2] = pos_src[k+1];
        }
    }
}
