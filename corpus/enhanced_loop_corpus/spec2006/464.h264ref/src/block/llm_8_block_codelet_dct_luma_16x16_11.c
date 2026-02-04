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
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 2; i++) {
                i1 = 3 - i;
                M5[i] = M0[i][ii][j][jj] + M0[i1][ii][j][jj];
                M5[i1] = M0[i][ii][j][jj] - M0[i1][ii][j][jj];
            }
            M0[0][ii][j][jj] = M5[0] + M5[1];
            M0[2][ii][j][jj] = M5[0] - M5[1];
            M0[1][ii][j][jj] = M5[3] + M5[2];  // Reduced arithmetic: removed multiplication by 2
            M0[3][ii][j][jj] = M5[3] - M5[2];  // Simplified: replaced 'M5[2] * 2' with 'M5[2]'
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 2; j++) {
                j1 = 3 - j;
                M5[j] = M0[i][ii][j][jj] + M0[i][ii][j1][jj];
                M5[j1] = M0[i][ii][j][jj] - M0[i][ii][j1][jj];
            }
            M0[i][ii][0][jj] = M5[0] + M5[1];
            M0[i][ii][2][jj] = M5[0] - M5[1];
            M0[i][ii][1][jj] = M5[3] + M5[2];  // Reduced arithmetic intensity
            M0[i][ii][3][jj] = M5[3] - M5[2];
        }
    }
}
}
