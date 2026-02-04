#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int horizontally_symmetric;
extern int vertically_symmetric;
extern int diagonally_symmetric;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_h = horizontally_symmetric;
    int temp_v = vertically_symmetric;
    int temp_d = diagonally_symmetric;
    for (i = 0; i < board_size && (temp_h || temp_v || temp_d); i++) {
        for (j = 0; j < board_size; j++) {
            Intersection val1 = board[((19 + 2) + (i) * (19 + 1) + (j))];
            Intersection val2_h = board[((19 + 2) + (i) * (19 + 1) + (board_size - 1 - j))];
            Intersection val2_v = board[((19 + 2) + (board_size - 1 - i) * (19 + 1) + (j))];
            Intersection val2_d = board[((19 + 2) + (board_size - 1 - j) * (19 + 1) + (board_size - 1 - i))];

            if (val1 != val2_h)
                temp_h = 0;
            if (val1 != val2_v)
                temp_v = 0;
            if (val1 != val2_d)
                temp_d = 0;
        }
    }
    horizontally_symmetric = temp_h;
    vertically_symmetric = temp_v;
    diagonally_symmetric = temp_d;
}
