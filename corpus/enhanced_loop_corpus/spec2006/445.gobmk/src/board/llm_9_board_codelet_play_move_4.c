#include <stdio.h>

#include <inttypes.h>

extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern int number_collapsed_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int start = number_collapsed_moves;
    int end = move_history_pointer;

    // Unroll the loop by a factor of 2 to increase computational intensity per iteration
    for (k = start; k < end - 1; k += 2) {
        int offset1 = k - number_collapsed_moves;
        int offset2 = offset1 + 1;

        move_history_color[offset1] = move_history_color[k];
        move_history_pos[offset1] = move_history_pos[k];

        move_history_color[offset2] = move_history_color[k + 1];
        move_history_pos[offset2] = move_history_pos[k + 1];
    }

    // Handle remaining element if trip count is odd
    if (k == end - 1) {
        int offset = k - number_collapsed_moves;
        move_history_color[offset] = move_history_color[k];
        move_history_pos[offset] = move_history_pos[k];
    }
}
