#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step Pattern
    int step = (19 + 1) - 1; // Use a strided access pattern across the board
    int limit = (19 + 2) + (board_size - 1 - ((19 + 2) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - (((19 + 2)) % (19 + 1) - 1));
    
    for (pos = (19 + 2); pos <= limit; pos += step) {
        int direct_index = pos;
        int reflected_row = (19 + 2) + (board_size - 1 - (direct_index / (19 + 1) - 1)) * (19 + 1);
        int reflected_col = (board_size - 1 - (direct_index % (19 + 1) - 1));
        int mirror_index = reflected_row + reflected_col;
        
        // Clamp index to valid range to avoid out-of-bounds
        if (mirror_index >= 421) continue;

        if ((board[direct_index] == 0) ^ (board[mirror_index] == 0)) {
            result = 0;
            break;
        }
    }
    // Final pass on remaining elements if step skips any
    for (int i = (19 + 2); i <= limit; i++) {
        if ((i - (19 + 2)) % step == 0) continue;
        int mirror_i = (19 + 2) + (board_size - 1 - ((i) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((i) % (19 + 1) - 1));
        if ((board[i] == 0) ^ (board[mirror_i] == 0)) {
            result = 0;
            break;
        }
    }
}
