#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int i;
int a;
int j;
int score;
int wdev_dscale;
int bdev_dscale;
int board[144];
int wking_loc;
int bking_loc;
int piece_count;
int pieces[62];
int pcsqbishop[144];
int black_knight[144];
int white_knight[144];
int white_pawn[144];
int black_pawn[144];
int black_queen[144];
int white_queen[144];
int black_rook[144];
int white_rook[144];
unsigned char p_tropism[144][144];
unsigned char q_tropism[144][144];
unsigned char n_tropism[144][144];
unsigned char r_tropism[144][144];
unsigned char b_tropism[144][144];

void init_vars() {
    // Initialize scalar variables
    i = 0;
    a = 0;
    j = 0;
    score = 0;
    wdev_dscale = 4;
    bdev_dscale = 4;
    wking_loc = 60;
    bking_loc = 4;
    piece_count = 32;

    // Initialize board with safe default values
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    // Place some valid pieces on the board (only use indices that are referenced via pieces[] array)
    // Ensure only indices within [0,143] are used and match cases in switch
    board[1] = 1;   // white pawn
    board[2] = 2;   // black pawn
    board[7] = 7;   // white rook
    board[8] = 8;   // black rook
    board[11] = 11; // white bishop
    board[12] = 12; // black bishop
    board[3] = 3;   // white knight
    board[4] = 4;   // black knight
    board[9] = 9;   // white queen
    board[10] = 10; // black queen

    // Initialize piece list: fill with valid indices, non-zero entries count toward piece_count
    for (int idx = 0; idx < 62; idx++) {
        pieces[idx] = 0;
    }
    // Fill first 'piece_count' active slots with valid indices that map to non-zero board values
    int valid_positions[] = {1, 2, 3, 4, 7, 8, 9, 10, 11, 12};
    int num_valid = sizeof(valid_positions) / sizeof(valid_positions[0]);
    for (int idx = 0; idx < piece_count; idx++) {
        pieces[idx + 1] = valid_positions[idx % num_valid]; // j starts at 1 in loop
    }

    // Initialize piece-square tables with non-zero patterns
    for (int idx = 0; idx < 144; idx++) {
        pcsqbishop[idx] = (idx * idx) % 256;
        black_knight[idx] = (idx * 7) % 256;
        white_knight[idx] = (idx * 13) % 256;
        white_pawn[idx] = (idx * 17) % 256;
        black_pawn[idx] = (idx * 19) % 256;
        black_queen[idx] = (idx * 23) % 256;
        white_queen[idx] = (idx * 29) % 256;
        black_rook[idx] = (idx * 31) % 256;
        white_rook[idx] = (idx * 37) % 256;
    }

    // Initialize tropism tables (144x144) with distance-like heuristic values
    for (int from = 0; from < 144; from++) {
        int from_row = from / 12;
        int from_col = from % 12;
        for (int to = 0; to < 144; to++) {
            int to_row = to / 12;
            int to_col = to % 12;
            int d_row = abs(to_row - from_row);
            int d_col = abs(to_col - from_col);

            p_tropism[from][to] = (unsigned char)(255 - 10 * (d_row + d_col));
            q_tropism[from][to] = (unsigned char)(255 - 8 * (d_row + d_col));
            n_tropism[from][to] = (unsigned char)(255 - 12 * (d_row + d_col));
            r_tropism[from][to] = (unsigned char)(255 - 9 * (d_row + d_col));
            b_tropism[from][to] = (unsigned char)(255 - 11 * (d_row + d_col));
        }
    }

    // Ensure king locations are within bounds
    if (wking_loc >= 144) wking_loc = 60;
    if (bking_loc >= 144) bking_loc = 4;
}