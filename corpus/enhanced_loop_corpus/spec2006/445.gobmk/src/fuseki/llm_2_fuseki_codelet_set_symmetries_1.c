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
    // Variant 1: Consecutive memory access with row-major traversal optimization
    // We precompute base indices to enable more predictable and consecutive-like access patterns
    int base_offset = (19 + 2);
    int row_stride = (19 + 1);
    int total_size = board_size * board_size;
    for (i = 0; i < total_size && (vertically_symmetric || horizontally_symmetric || diagonally_symmetric); i++) {
        int flat_idx = i;
        int i_row = flat_idx / board_size;
        int j_col = flat_idx % board_size;

        int idx_normal = base_offset + i_row * row_stride + j_col;
        int idx_h_mirror = base_offset + i_row * row_stride + (board_size - 1 - j_col);
        int idx_v_mirror = base_offset + (board_size - 1 - i_row) * row_stride + j_col;
        int idx_diag_mirror = base_offset + (board_size - 1 - j_col) * row_stride + (board_size - 1 - i_row);

        if (board[idx_normal] != board[idx_h_mirror])
            horizontally_symmetric = 0;
        if (board[idx_normal] != board[idx_v_mirror])
            vertically_symmetric = 0;
        if (board[idx_normal] != board[idx_diag_mirror])
            diagonally_symmetric = 0;
    }
}
