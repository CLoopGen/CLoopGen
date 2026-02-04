#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every other element in reverse order, then fill gaps)
    int size = 19 + 1;
    int limit = (19 + 2) * (19 + 1) + 1;

    // First pass: strided access — process even indices in reverse
    for (k = limit - 1; k >= 0; k -= 2) {
        int row = k / size - 1;
        int col = k % size - 1;
        if (!((unsigned int)(row) < (unsigned int)board_size && (unsigned int)(col) < (unsigned int)board_size)) {
            board[k] = 3;
            initial_board[k] = 3;
        }
    }

    // Second pass: handle odd indices (completing the original iteration space with stride 2)
    for (k = limit - 2; k >= 0; k -= 2) {
        int row = k / size - 1;
        int col = k % size - 1;
        if (!((unsigned int)(row) < (unsigned int)board_size && (unsigned int)(col) < (unsigned int)board_size)) {
            board[k] = 3;
            initial_board[k] = 3;
        }
    }
}
