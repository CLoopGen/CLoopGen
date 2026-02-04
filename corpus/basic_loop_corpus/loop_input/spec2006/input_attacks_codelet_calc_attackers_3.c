#include <stdio.h>
#include <inttypes.h>

int board[144];
int square;
int rook_o[4];
int a_sq;
int i;
int attackers;

void init_vars() {
    // Initialize rook offsets to represent up, right, down, left (assuming 12x12 board)
    rook_o[0] = -12;  // up
    rook_o[1] = 1;    // right
    rook_o[2] = 12;   // down
    rook_o[3] = -1;   // left

    // Set square to a valid center position to avoid immediate out-of-bounds
    square = 66;  // roughly center of 12x12 grid (index from 0)

    // Initialize board to mostly empty (0), with some obstacles and relevant pieces
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    // Place a queen (value 10) along one direction (e.g., right) to be detected
    board[square + rook_o[1] + 1] = 10;

    // Ensure other directions do not trigger attacker count:
    // - One direction has a blocker (non-6, non-8, non-10) early to break inner loop
    // - Other directions are empty or have value 13 (enemy piece that continues)
    
    // Example: down direction hits a 13 then later an 8 -> should trigger
    int temp_sq = square + rook_o[2];
    board[temp_sq] = 13;
    board[temp_sq + rook_o[2]] = 8;

    // Left direction: place a 6 (king?) which will trigger attackers++ and break immediately
    board[square + rook_o[3]] = 6;

    // Up direction: empty path followed by nothing interesting (no attacker)

    // Initialize state variables
    a_sq = 0;
    i = 0;
    attackers = 0;
}