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
    // Variant 2: Strided memory access – traverse column by column (column-major) instead of row-major
    // This creates a strided access pattern across the board array, potentially stressing cache differently
    int base_offset = (19 + 2);
    int row_stride = (19 + 1);
    for (j = 0; j < board_size; j++)
        for (i = 0; i < board_size && (vertically_symmetric || horizontally_symmetric || diagonally_symmetric); i++) {
            int idx_normal = base_offset + i * row_stride + j;
            int idx_h_mirror = base_offset + i * row_stride + (board_size - 1 - j);
            int idx_v_mirror = base_offset + (board_size - 1 - i) * row_stride + j;
            int idx_diag_mirror = base_offset + (board_size - 1 - j) * row_stride + (board_size - 1 - i);

            if (board[idx_normal] != board[idx_h_mirror])
                horizontally_symmetric = 0;
            if (board[idx_normal] != board[idx_v_mirror])
                vertically_symmetric = 0;
            if (board[idx_normal] != board[idx_diag_mirror])
                diagonally_symmetric = 0;
        }
}
