#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (19 + 2);
    int end = (19 + 2) + (board_size - 1 - ((start) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((start) % (19 + 1) - 1));
    result = 1;
    for (pos = start; pos <= end; pos++) {
        int mirror_pos = (19 + 2) + (board_size - 1 - ((pos) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((pos) % (19 + 1) - 1));
        if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
            result = 0;
            break;
        }
        // Introduce WAW dependency by updating same location in loop
        board[pos] = board[pos]; // Redundant write: creates WAW if optimized or unrolled
    }
}
