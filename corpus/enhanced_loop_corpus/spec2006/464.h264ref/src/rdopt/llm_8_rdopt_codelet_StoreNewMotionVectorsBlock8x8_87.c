#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int fw_ref;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;
extern short ******all_mv;
extern short ******pred_mv;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Trip count remains same, but more work per iteration via additional computations (dummy arithmetic to simulate complexity)
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i += 2) {
            // Process two elements at once with added arithmetic overhead
            int i1 = i;
            int i2 = i + 1;

            if (i1 < ii) {
                short val1_0 = all_mv[i1][j][0][fw_ref][4][0];
                short val1_1 = all_mv[i1][j][0][fw_ref][4][1];
                short pval1_0 = pred_mv[i1][j][0][fw_ref][4][0];
                short pval1_1 = pred_mv[i1][j][0][fw_ref][4][1];

                // Add dummy computation to increase ALU usage
                val1_0 += pval1_0; val1_0 ^= 0x1;
                pval1_1 += val1_1; pval1_1 ^= 0x2;

                all_mv8x8[dir][0][i1][j][0] = val1_0;
                all_mv8x8[dir][0][i1][j][1] = val1_1;
                pred_mv8x8[dir][0][i1][j][0] = pval1_0;
                pred_mv8x8[dir][0][i1][j][1] = pval1_1;
            }

            if (i2 < ii) {
                short val2_0 = all_mv[i2][j][0][fw_ref][4][0];
                short val2_1 = all_mv[i2][j][0][fw_ref][4][1];
                short pval2_0 = pred_mv[i2][j][0][fw_ref][4][0];
                short pval2_1 = pred_mv[i2][j][0][fw_ref][4][1];

                val2_0 += pval2_0; val2_0 ^= 0x3;
                pval2_1 += val2_1; pval2_1 ^= 0x4;

                all_mv8x8[dir][0][i2][j][0] = val2_0;
                all_mv8x8[dir][0][i2][j][1] = val2_1;
                pred_mv8x8[dir][0][i2][j][0] = pval2_0;
                pred_mv8x8[dir][0][i2][j][1] = pval2_1;
            }
        }
    }
}
