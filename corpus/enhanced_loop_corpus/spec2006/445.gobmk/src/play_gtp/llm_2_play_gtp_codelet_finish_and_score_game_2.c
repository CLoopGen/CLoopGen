#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int final_status[19][19];
extern int i;
extern int j;
extern int saved_board[19][19];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Linear Indexing and Array Flattening
    int idx = 0;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            idx = (19 + 2) + i * (19 + 1) + j;
            int fs_idx = i * 19 + j;  // Flatten final_status and saved_board indexing

            if (board[idx] == saved_board[i][j])
                continue;

            if (board[idx] == 0) {
                if (final_status[i][j] == 1 || final_status[i][j] == 7)
                    final_status[i][j] = 15;
                else if (final_status[i][j] == 0) {
                    if (saved_board[i][j] == 2)
                        final_status[i][j] = 14;
                    else
                        final_status[i][j] = 13;
                }
            } else if (board[idx] == 2) {
                if (final_status[i][j] == 14)
                    final_status[i][j] = 0;
                else if (final_status[i][j] == 15)
                    final_status[i][j] = 7;
                else if (final_status[i][j] == 13)
                    final_status[i][j] = 1;
                else
                    final_status[i][j] = 0;
            } else if (board[idx] == 1) {
                if (final_status[i][j] == 13)
                    final_status[i][j] = 0;
                else if (final_status[i][j] == 15)
                    final_status[i][j] = 7;
                else if (final_status[i][j] == 14)
                    final_status[i][j] = 1;
                else
                    final_status[i][j] = 0;
            }
        }
    }
}
