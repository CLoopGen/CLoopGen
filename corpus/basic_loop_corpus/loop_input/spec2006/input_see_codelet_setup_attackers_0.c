#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

int board[144];
see_data see_attackers[2][16];
int square;
int rook_o[4];
int a_sq;
int b_sq;
int i;
int numw;
int numb;

void init_vars() {
    // Initialize board to safe values, ensuring no out-of-bounds access
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    // Set up valid directions for rook moves (assuming 12x12 board with offset layout)
    rook_o[0] = 1;   // East
    rook_o[1] = -1;  // West
    rook_o[2] = 12;  // North
    rook_o[3] = -12; // South

    // Place the starting square near center to avoid immediate boundary issues
    square = 66;

    // Initialize attackers arrays to zero
    for (int color = 0; color < 2; color++) {
        for (int idx = 0; idx < 16; idx++) {
            see_attackers[color][idx].piece = 0;
            see_attackers[color][idx].square = 0;
        }
    }

    // Initialize counters
    numw = 0;
    numb = 0;

    // Ensure that accesses in loop stay within [0,143] range for board
    // Populate some test pieces along rook lines to trigger various branches
    board[square + rook_o[0] + rook_o[0]] = 7;  // Friendly minor piece two steps east
    board[square + rook_o[1] + rook_o[1]] = 8;  // Enemy minor piece two steps west
    board[square + rook_o[2] + rook_o[2]] = 13; // Empty continuation square (blocked later)
    board[square + rook_o[2] + rook_o[2] + rook_o[2]] = 9; // Friendly piece after empty
    board[square + rook_o[3]] = 5; // Friendly rook adjacent south

    // Adjust so that the loop processes meaningful data without overrunning
    i = 0;
}