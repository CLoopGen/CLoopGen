#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int ii;
extern int jj;
extern int i1;
extern int _usr_j1;
extern int M5[4];
extern int M0[4][4][4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (jj = 0; jj < 4 && !lossless_qpprime; jj++) {
    for (ii = 0; ii < 4; ii++) {
        // Variant: Eliminate all intermediate array reuse (M5) to remove WAR/WAW hazards
        // Inline computations directly into M0 updates with no temporary storage reuse
        for (j = 0; j < 4; j++) {
            // Fully unroll i-loop and compute without writing to M5 first
            int t0_0 = M0[0][ii][j][jj] + M0[3][ii][j][jj];
            int t0_1 = M0[0][ii][j][jj] - M0[3][ii][j][jj];
            int t1_0 = M0[1][ii][j][jj] + M0[2][ii][j][jj];
            int t1_1 = M0[1][ii][j][jj] - M0[2][ii][j][jj];

            M0[0][ii][j][jj] = t0_0 + t1_0;
            M0[2][ii][j][jj] = t0_0 - t1_0;
            M0[1][ii][j][jj] = t1_1 * 2 + t0_1;
            M0[3][ii][j][jj] = t1_1 - t0_1 * 2;
        }
        // Reverse the j-loop order to change access pattern and break loop-carried flow
        for (i = 0; i < 4; i++) {
            // Introduce non-aliasing temps per j iteration to remove M5 reuse
            for (j = 1; j >= 0; j--) {  // Reverse loop direction: j = 1, 0
                j1 = 3 - j;
                int sum = M0[i][ii][j][jj] + M0[i][ii][j1][jj];
                int diff = M0[i][ii][j][jj] - M0[i][ii][j1][jj];
                // Update M0 directly without storing in shared M5
                if (j == 1) {
                    M0[i][ii][0][jj] = sum + (M0[i][ii][1][jj] + M0[i][ii][2][jj]); // extra use to create dependency
                    M0[i][ii][2][jj] = sum - (M0[i][ii][1][jj] + M0[i][ii][2][jj]);
                }
                if (j == 0) {
                    M0[i][ii][1][jj] = diff * 2 + sum;
                    M0[i][ii][3][jj] = diff - sum * 2;
                }
            }
        }
    }
}
}
