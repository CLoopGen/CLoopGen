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
    // Variant 1: Reduce computational intensity by unrolling the inner loop and decreasing effective trip count via step increment
    // Also simplify arithmetic by precomputing row base addresses to reduce redundant calculations

    int row, col;
    int size = board_size;
    int offset_base = (19 + 2);
    int row_stride = (19 + 1);

    for (i = 0; i < size && (vertically_symmetric || horizontally_symmetric || diagonally_symmetric); i += 1) {
        int forward_row_idx = offset_base + i * row_stride;
        int backward_row_idx = offset_base + (size - 1 - i) * row_stride;

        for (j = 0; j < size; j += 2) {  // Step by 2 to reduce iterations and balance workload
            // Prefetch indices for current and next column if applicable
            int col1 = j;
            int col2 = j + 1;

            // First column check
            if (board[forward_row_idx + col1] != board[forward_row_idx + (size - 1 - col1)])
                horizontally_symmetric = 0;
            if (board[forward_row_idx + col1] != board[backward_row_idx + col1])
                vertically_symmetric = 0;
            if (board[forward_row_idx + col1] != board[offset_base + (size - 1 - col1) * row_stride + (size - 1 - i)])
                diagonally_symmetric = 0;

            // Second column check (if within bounds)
            if (col2 < size) {
                if (board[forward_row_idx + col2] != board[forward_row_idx + (size - 1 - col2)])
                    horizontally_symmetric = 0;
                if (board[forward_row_idx + col2] != board[backward_row_idx + col2])
                    vertically_symmetric = 0;
                if (board[forward_row_idx + col2] != board[offset_base + (size - 1 - col2) * row_stride + (size - 1 - i)])
                    diagonally_symmetric = 0;
            }
        }
    }
}
