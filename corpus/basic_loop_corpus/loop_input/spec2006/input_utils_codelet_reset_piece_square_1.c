#include <stdio.h>
#include <inttypes.h>

int i;
int promoted_board[144];
int board[144];
int squares[144];
int piece_count;
int pieces[62];
int is_promoted[62];
int Material;
int material[14];

void init_vars() {
    for (int idx = 0; idx < 144; idx++) {
        promoted_board[idx] = 0;
        board[idx] = 0;
        squares[idx] = 0;
    }
    for (int idx = 0; idx < 62; idx++) {
        pieces[idx] = 0;
        is_promoted[idx] = 0;
    }
    for (int idx = 0; idx < 14; idx++) {
        material[idx] = 1;
    }
    piece_count = 0;
    Material = 0;

    for (int idx = 26; idx < 118; idx++) {
        board[idx] = (idx % 13); 
    }
}