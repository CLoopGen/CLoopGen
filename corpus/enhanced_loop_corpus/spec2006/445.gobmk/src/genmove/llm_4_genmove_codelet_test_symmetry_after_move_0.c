#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = (19 + 2); pos <= ((19 + 2) + (board_size - 1 - ((pos) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((pos) % (19 + 1) - 1))); pos++) {
        if (board[pos] == 0) {
            if (board[((19 + 2) + (board_size - 1 - ((pos) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((pos) % (19 + 1) - 1)))] != 0) {
                result = 0;
                break;
            }
        } else {
            if (board[((19 + 2) + (board_size - 1 - ((pos) / (19 + 1) - 1)) * (19 + 1) + (board_size - 1 - ((pos) % (19 + 1) - 1)))] == 0) {
                result = 0;
                break;
            }
        }
    }
}
