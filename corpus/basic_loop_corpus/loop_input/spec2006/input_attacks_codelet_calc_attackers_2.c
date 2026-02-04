#include <inttypes.h>

int board[144];
int square;
int knight_o[8];
int a_sq;
int i;
int attackers;

void init_vars() {
    // Initialize board with size 144 (12x12), safe for knight moves from center
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = (idx % 7 == 0) ? 3 : 0;  // Place value 3 periodically
    }

    // Ensure square is within bounds so that a_sq = square + knight_o[i] stays in [0,143]
    // Choose square near center to allow offsets
    square = 66;  // Row 5, Col 6 in 12x12 grid

    // Knight move offsets for 12x12 board (assuming row-major, each row 12 elements)
    knight_o[0] = -25; // -2*12 -1
    knight_o[1] = -23; // -2*12 +1
    knight_o[2] = -14; // -1*12 -2
    knight_o[3] = -10; // -1*12 +2
    knight_o[4] =  10; //  1*12 -2
    knight_o[5] =  14; //  1*12 +2
    knight_o[6] =  23; //  2*12 -1
    knight_o[7] =  25; //  2*12 +1

    // Initialize scalar variables
    a_sq = 0;
    i = 0;
    attackers = 0;
}