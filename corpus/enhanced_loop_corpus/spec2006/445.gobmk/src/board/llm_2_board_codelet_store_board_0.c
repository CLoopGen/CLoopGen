#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct board_state {
    int board_size;
    Intersection board[421];
    int board_ko_pos;
    int black_captured;
    int white_captured;
    Intersection initial_board[421];
    int initial_board_ko_pos;
    int initial_white_captured;
    int initial_black_captured;
    int move_history_color[500];
    int move_history_pos[500];
    int move_history_pointer;
    float komi;
    int move_number;
};


extern int move_history_color[500];
extern int move_history_pos[500];
extern int move_history_pointer;
extern struct board_state *state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    int k;
    int stride = 2;
    
    // Process pairs with stride
    for (k = 0; k + 1 < move_history_pointer; k += stride) {
        state->move_history_color[k]     = move_history_color[k];
        state->move_history_pos[k]       = move_history_pos[k];
        state->move_history_color[k + 1] = move_history_color[k + 1];
        state->move_history_pos[k + 1]   = move_history_pos[k + 1];
    }
    
    // Handle remaining element if any
    if (k < move_history_pointer) {
        state->move_history_color[k] = move_history_color[k];
        state->move_history_pos[k]   = move_history_pos[k];
    }
}
