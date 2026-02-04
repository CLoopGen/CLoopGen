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
    int h_done = !horizontally_symmetric;
    int v_done = !vertically_symmetric;
    int d_done = !diagonally_symmetric;

    for (i = 0; i < board_size && !(h_done && v_done && d_done); i++) {
        for (j = 0; j < board_size; j++) {
            if (!h_done) {
                if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (i) * (19 + 1) + (board_size - 1 - j))]) {
                    horizontally_symmetric = 0;
                    h_done = 1;
                }
            }

            if (!v_done) {
                if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (board_size - 1 - i) * (19 + 1) + (j))]) {
                    vertically_symmetric = 0;
                    v_done = 1;
                }
            }

            if (!d_done) {
                if (board[((19 + 2) + (i) * (19 + 1) + (j))] != board[((19 + 2) + (board_size - 1 - j) * (19 + 1) + (board_size - 1 - i))]) {
                    diagonally_symmetric = 0;
                    d_done = 1;
                }
            }
        }
    }
}
