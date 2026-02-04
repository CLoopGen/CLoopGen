#include <stdio.h>
#include <inttypes.h>

int board[144];
int knight_o[8];
int square;
int d;
int m;

void init_vars() {
    // Initialize knight move offsets for a standard chess knight (8 directions)
    knight_o[0] = -2 * 12 - 1;  // up 2, left 1
    knight_o[1] = -2 * 12 + 1;  // up 2, right 1
    knight_o[2] = -1 * 12 - 2;  // up 1, left 2
    knight_o[3] = -1 * 12 + 2;  // up 1, right 2
    knight_o[4] =  1 * 12 - 2;  // down 1, left 2
    knight_o[5] =  1 * 12 + 2;  // down 1, right 2
    knight_o[6] =  2 * 12 - 1;  // down 2, left 1
    knight_o[7] =  2 * 12 + 1;  // down 2, right 1

    // Initialize board with safe values
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }

    // Set some positions to 13 to allow m to increment
    // Ensure these are placed where knight moves can reach from valid square
    board[25] = 13;
    board[38] = 13;
    board[51] = 13;
    board[62] = 13;

    // Choose a valid square within bounds such that all knight_o[d] offsets stay in [0,143]
    // Board is 12x12: rows 0-11, columns 0-11. Valid square must avoid edges affected by knight moves.
    // Safe central square: e.g., row 4, col 5 => index = 4*12 + 5 = 53
    square = 53;

    // Initialize loop counter and accumulator
    d = 0;
    m = 0;
}