#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int i;
extern int j;
extern int current_board[19][19];
extern int cached_board;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < board_size; i += 2)
    for (j = 0; j < board_size; j += 2) {
        int val = board[(19 + 2) + i * (19 + 1) + j];
        if (val != current_board[i][j]) {
            current_board[i][j] = val;
            cached_board = 0;
        }
        if (j + 1 < board_size) {
            val = board[(19 + 2) + i * (19 + 1) + (j + 1)];
            if (val != current_board[i][j + 1]) {
                current_board[i][j + 1] = val;
                cached_board = 0;
            }
        }
        if (i + 1 < board_size) {
            val = board[(19 + 2) + (i + 1) * (19 + 1) + j];
            if (val != current_board[i + 1][j]) {
                current_board[i + 1][j] = val;
                cached_board = 0;
            }
            if (j + 1 < board_size) {
                val = board[(19 + 2) + (i + 1) * (19 + 1) + (j + 1)];
                if (val != current_board[i + 1][j + 1]) {
                    current_board[i + 1][j + 1] = val;
                    cached_board = 0;
                }
            }
        }
    }
}
