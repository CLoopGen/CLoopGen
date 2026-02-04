#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result = 1;
    int base = (19 + 2);
    int max_offset = (board_size - 1) * (19 + 1) + (board_size - 1);
    int limit = base + max_offset;
    // Eliminate loop-carried dependency by precomputing all accesses
    for (pos = base; pos <= limit && result != 0; pos++) {
        int row_index = (pos) / (19 + 1) - 1;
        int col_index = (pos) % (19 + 1) - 1;
        int mirror_pos = base + (board_size - 1 - row_index) * (19 + 1) + (board_size - 1 - col_index);
        // Introduce RAW dependency: use prior iteration's result to conditionally skip
        if (pos > base) {
            if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
                result = 0;
            } else {
                result = result & 1; // Maintain previous state — creates RAW
            }
        } else {
            if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
                result = 0;
            }
        }
    }
}
