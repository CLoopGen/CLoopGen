#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = number_collapsed_moves; i < move_history_pointer; i++) {
        int offset = i - number_collapsed_moves;
        move_history_color[offset] = move_history_color[i];
        move_history_pos[offset] = move_history_pos[i];
    }
}
