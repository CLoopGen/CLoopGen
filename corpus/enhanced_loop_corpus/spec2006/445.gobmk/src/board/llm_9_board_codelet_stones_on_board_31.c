#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int white_stones;
extern int black_stones;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unrolled loop with reduced trip count but multiple operations per iteration
    int limit = (19 + 1) * (19 + 1) - 4;
    for (pos = (19 + 2); pos < limit; pos += 4) {
        // Process four elements per iteration to reduce loop overhead
        if (board[pos] == 1)
            white_stones++;
        else if (board[pos] == 2)
            black_stones++;

        if (board[pos + 1] == 1)
            white_stones++;
        else if (board[pos + 1] == 2)
            black_stones++;

        if (board[pos + 2] == 1)
            white_stones++;
        else if (board[pos + 2] == 2)
            black_stones++;

        if (board[pos + 3] == 1)
            white_stones++;
        else if (board[pos + 3] == 2)
            black_stones++;
    }
    // Handle remaining elements not covered by unrolling
    for (; pos < (19 + 1) * (19 + 1); pos++) {
        if (board[pos] == 1)
            white_stones++;
        else if (board[pos] == 2)
            black_stones++;
    }
}
