#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int white_stones;
extern int black_stones;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_white = 0;
    int temp_black = 0;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        temp_white += (board[pos] == 1);
        temp_black += (board[pos] == 2);
    }
    white_stones += temp_white;
    black_stones += temp_black;
}
