#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int i;
extern int j;
extern int color;
extern int vertexi[361];
extern int vertexj[361];
extern int vertices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid indices in a separate array and iterate over them indirectly
    // This changes the access pattern to indirect based on a lookup table.
    static int precomputed_index[361];
    int count = 0;
    int base_offset = (19 + 2);
    int row_stride = (19 + 1);

    // Precompute linear indices for all (i,j) pairs within board_size x board_size
    for (int ii = 0; ii < board_size; ii++)
        for (int jj = 0; jj < board_size; jj++)
            precomputed_index[count++] = base_offset + ii * row_stride + jj;

    // Now use indirect access through precomputed_index
    for (int k = 0; k < count; k++) {
        int ii = k / board_size;
        int jj = k % board_size;
        if (board[precomputed_index[k]] == color) {
            vertexi[vertices] = ii;
            vertexj[vertices++] = jj;
        }
    }
}
