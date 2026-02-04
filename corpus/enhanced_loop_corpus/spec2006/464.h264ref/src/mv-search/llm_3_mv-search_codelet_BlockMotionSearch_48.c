#include <stdio.h>

#include <inttypes.h>

extern short ref;
extern int list;
extern int blocktype;
extern short mv_x;
extern short mv_y;
extern int i;
extern int j;
extern int block_x;
extern int block_y;
extern int bsx;
extern int bsy;
extern short ***mv_array;
extern short ******all_mv;
extern int h4x4blkno;
extern int v4x4blkno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Linear Indexing
    // Collapse 2D iteration into a single loop with linear index,
    // computing i and j from a flat index to promote consecutive memory access.
    // This improves spatial locality and enables better vectorization.

    int total_elements = (bsx >> 2) * (bsy >> 2);
    int inner_dim = (bsy >> 2);

    for (int idx = 0; idx < total_elements; idx++) {
        i = idx / inner_dim;  // Recover row
        j = idx % inner_dim;  // Recover column

        all_mv[block_x + i][block_y + j][list][ref][blocktype][0] = mv_x;
        all_mv[block_x + i][block_y + j][list][ref][blocktype][1] = mv_y;
        mv_array[h4x4blkno + i][v4x4blkno + j][0] = mv_x;
        mv_array[h4x4blkno + i][v4x4blkno + j][1] = mv_y;
    }
}
