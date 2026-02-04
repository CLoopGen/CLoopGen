#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int white_stones;
extern int black_stones;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    white_stones = 0;
    black_stones = 0;
    for (pos = (19 + 2) + 1; pos < (19 + 1) * (19 + 1); pos += 2) {
        if (board[pos] == 1)
            white_stones++;
        else if (board[pos] == 2)
            black_stones++;
    }
    // Handle remaining index if range is odd, using a second loop phase with offset
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos += 2) {
        if (board[pos] == 1)
            white_stones++;
        else if (board[pos] == 2)
            black_stones++;
    }
}
