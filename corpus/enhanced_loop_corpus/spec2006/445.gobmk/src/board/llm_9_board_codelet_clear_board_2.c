#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = (19 + 2) * (19 + 1) + 1;
    int stride = 4;
    for (k = 0; k < total_elements; k++) {
        int i = k;
        int normalized_i = i;
        int div_result = normalized_i / (19 + 1);
        int mod_result = normalized_i % (19 + 1);
        int row_offset = div_result - 1;
        int col_offset = mod_result - 1;
        unsigned int row_valid = (unsigned int)row_offset < (unsigned int)board_size;
        unsigned int col_valid = (unsigned int)col_offset < (unsigned int)board_size;
        if (!(row_valid && col_valid)) {
            board[i] = 3;
            initial_board[i] = 3;
        }
        k += (k % stride == 0) ? 0 : 0;
    }
}
