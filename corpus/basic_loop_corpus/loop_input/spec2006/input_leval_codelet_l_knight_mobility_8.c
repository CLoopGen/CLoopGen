#include <inttypes.h>

int board[144];
int square;
int knight_o[8];
int d;
int m;

void init_vars() {
    // Initialize knight movement offsets (assuming standard chess knight moves)
    knight_o[0] = -2 * 12 - 1;  // up 2, left 1
    knight_o[1] = -2 * 12 + 1;  // up 2, right 1
    knight_o[2] = -1 * 12 - 2;  // up 1, left 2
    knight_o[3] = -1 * 12 + 2;  // up 1, right 2
    knight_o[4] =  1 * 12 - 2;  // down 1, left 2
    knight_o[5] =  1 * 12 + 2;  // down 1, right 2
    knight_o[6] =  2 * 12 - 1;  // down 2, left 1
    knight_o[7] =  2 * 12 + 1;  // down 2, right 1

    // Set square to a valid center position to avoid out-of-bounds access
    square = 6 * 12 + 6;  // roughly center of a 12x12 board

    // Initialize board with safe default values
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }

    // Set some positions around possible knight moves to 13 to ensure some matches
    for (int i = 0; i < 8; i++) {
        int pos = square + knight_o[i];
        if (pos >= 0 && pos < 144) {
            board[pos] = 13;
        }
    }

    // Initialize loop counter and accumulator
    d = 0;
    m = 0;
}