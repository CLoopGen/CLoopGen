#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int white_stones;
extern int black_stones;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int end = 400;
    int step = 2;
    for (pos = start; pos < end; pos += step) {
        if (board[pos] == 1) {
            white_stones++;
        } else if (board[pos] == 2) {
            black_stones++;
        }
        // Additional arithmetic to increase computational intensity
        pos += (pos % 3) ? 1 : 0;
    }
}
