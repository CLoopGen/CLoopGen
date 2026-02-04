#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int b[19][19];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            if (i % 2 == 0) {
                b[i][j] = board[((19 + 2) + i * (19 + 1) + j)];
            } else {
                continue;
            }
        }
    }
}
