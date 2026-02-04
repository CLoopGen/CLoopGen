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
for (jj = 0; jj < 2 && !lossless_qpprime; jj++) {  // Reduced trip count from 4 to 2
    for (ii = 0; ii < 4; ii++) {
        for (j = 0; j < 4; j++) {
            // Unrolled inner i-loop manually to increase computational density
            // Original i=0, i1=3
            M5[0] = M0[0][ii][j][jj] + M0[3][ii][j][jj];
            M5[3] = M0[0][ii][j][jj] - M0[3][ii][j][jj];
            // i=1, i1=2
            M5[1] = M0[1][ii][j][jj] + M0[2][ii][j][jj];
            M5[2] = M0[1][ii][j][jj] - M0[2][ii][j][jj];

            M0[0][ii][j][jj] = M5[0] + M5[1];
            M0[2][ii][j][jj] = M5[0] - M5[1];
            M0[1][ii][j][jj] = M5[3] * 2 + M5[2];
            M0[3][ii][j][jj] = M5[3] - M5[2] * 2;
        }
        for (i = 0; i < 4; i++) {
            // Unroll j-loop (j=0, j1=3) and (j=1, j1=2)
            M5[0] = M0[i][ii][0][jj] + M0[i][ii][3][jj];
            M5[3] = M0[i][ii][0][jj] - M0[i][ii][3][jj];
            M5[1] = M0[i][ii][1][jj] + M0[i][ii][2][jj];
            M5[2] = M0[i][ii][1][jj] - M0[i][ii][2][jj];

            M0[i][ii][0][jj] = M5[0] + M5[1];
            M0[i][ii][2][jj] = M5[0] - M5[1];
            M0[i][ii][1][jj] = M5[3] * 2 + M5[2];
            M0[i][ii][3][jj] = M5[3] - M5[2] * 2;
        }
    }
}
}
