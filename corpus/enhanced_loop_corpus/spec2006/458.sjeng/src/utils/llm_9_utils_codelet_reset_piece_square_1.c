#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int promoted_board[144];
extern int board[144];
extern int squares[144];
extern int piece_count;
extern int pieces[62];
extern int is_promoted[62];
extern int Material;
extern int material[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 26; i < 118; i++) {
    int b_val = board[i];
    if (b_val && b_val < 13) {
        int m_val = material[b_val];
        Material = Material + m_val;
        piece_count = piece_count + 1;
        int p_idx = piece_count;
        pieces[p_idx] = i;
        squares[i] = p_idx;
        int p_board_val = promoted_board[i];
        is_promoted[p_idx] = (p_board_val != 0) ? 1 : 0;
    } else {
        squares[i] = 0;
    }
}
}
