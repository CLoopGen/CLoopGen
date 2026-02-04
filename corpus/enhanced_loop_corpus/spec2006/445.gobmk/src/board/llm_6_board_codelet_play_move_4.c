#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = number_collapsed_moves;
    for (k = number_collapsed_moves; k < move_history_pointer; k++) {
        int new_index = k - offset;
        // Introduce temporary variables to eliminate direct WAW and WAR dependencies
        int temp_color = move_history_color[k];
        int temp_pos = move_history_pos[k];
        move_history_color[new_index] = temp_color;
        move_history_pos[new_index] = temp_pos;
    }
}
