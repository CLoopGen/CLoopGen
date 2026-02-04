#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int white_stones;
extern int black_stones;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int limit = (19 + 1) * (19 + 1);
    for (i = (19 + 2); i < limit; i += 2) {
        pos = i;
        if (board[pos] == 1)
            white_stones++;
        else if (board[pos] == 2)
            black_stones++;

        if (i + 1 < limit) {
            pos = i + 1;
            if (board[pos] == 1)
                white_stones++;
            else if (board[pos] == 2)
                black_stones++;
        }
    }
}
