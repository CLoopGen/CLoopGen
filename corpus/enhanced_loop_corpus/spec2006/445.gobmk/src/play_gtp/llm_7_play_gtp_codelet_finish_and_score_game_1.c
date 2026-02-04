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
    int local_cached = cached_board;
    for (i = 0; i < board_size; i++) {
        int row_changed = 0;
        for (j = 0; j < board_size; j++) {
            Intersection val = board[((19 + 2) + (i) * (19 + 1) + (j))];
            if (val != current_board[i][j]) {
                current_board[i][j] = val;
                row_changed = 1;
            }
        }
        if (row_changed)
            local_cached = 0;
    }
    cached_board = local_cached;
}
