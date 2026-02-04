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
    int idx_i, idx_j;
    for (i = 0; i < (bsx >> 2); i++) {
        idx_i = block_x + i;
        for (j = 0; j < (bsy >> 2); j++) {
            idx_j = block_y + j;
            // Eliminate redundant computations and create loop-carried dependence via accumulation
            // Simulate a RAW hazard by making current write depend on previous iteration's value
            if (i > 0 || j > 0) {
                all_mv[idx_i][idx_j][list][ref][blocktype][0] = 
                    all_mv[idx_i - (j==0)][idx_j - (j>0)][list][ref][blocktype][0] + mv_x;
                all_mv[idx_i][idx_j][list][ref][blocktype][1] = 
                    all_mv[idx_i - (j==0)][idx_j - (j>0)][list][ref][blocktype][1] + mv_y;
            } else {
                all_mv[idx_i][idx_j][list][ref][blocktype][0] = mv_x;
                all_mv[idx_i][idx_j][list][ref][blocktype][1] = mv_y;
            }
            // Maintain mv_array assignment independent of prior writes (eliminate loop-carried dep here)
            mv_array[h4x4blkno + i][v4x4blkno + j][0] = mv_x;
            mv_array[h4x4blkno + i][v4x4blkno + j][1] = mv_y;
        }
    }
}
