#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int size = board_size;
    int step = (19 + 1);
    int max_offset = (size - 1) * (step + 1);
    result = 1;
    for (pos = start; pos <= start + max_offset; pos += 2) {
        int mirror_pos = start + (size - 1 - (pos / step - 1)) * step + (size - 1 - (pos % step - 1));
        if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
            result = 0;
            break;
        }
    }
}
