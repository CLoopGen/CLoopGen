#include <stdint.h>

int board[144];
int square;
int knight_o[8];
int a_sq;
int i;
int attackers;

void init_vars() {
    // Initialize knight offset directions for 8 possible knight moves
    knight_o[0] = -2 * 12 - 1;  // up-up-left
    knight_o[1] = -2 * 12 + 1;  // up-up-right
    knight_o[2] = -1 * 12 - 2;  // up-left-left
    knight_o[3] = -1 * 12 + 2;  // up-right-right
    knight_o[4] =  1 * 12 - 2;  // down-left-left
    knight_o[5] =  1 * 12 + 2;  // down-right-right
    knight_o[6] =  2 * 12 - 1;  // down-down-left
    knight_o[7] =  2 * 12 + 1;  // down-down-right

    // Set square to center of board to avoid boundary issues
    square = 6 * 12 + 6;

    // Initialize board: fill with zeros except known piece positions
    for (int idx = 0; idx < 144; ++idx) {
        board[idx] = 0;
    }

    // Place some pieces on valid target squares that the knight could attack
    // Ensure only value 4 is placed where knight can reach from 'square'
    for (int move = 0; move < 8; ++move) {
        int target = square + knight_o[move];
        if (target >= 0 && target < 144) {
            // Use wrap condition to simulate patterned placement
            if ((target % 17) == 0) {
                board[target] = 4;
            }
        }
    }

    // Initialize scalar variables
    a_sq = 0;
    i = 0;
    attackers = 0;
}