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
    int has_piece = board[i] && (board[i] < 13);
    if (has_piece) {
        Material += material[board[i]];
        piece_count += 1;
        pieces[piece_count] = i;
        squares[i] = piece_count;
        is_promoted[piece_count] = (promoted_board[i] != 0) ? 1 : 0;
    } else {
        squares[i] = 0;
    }
}
}
