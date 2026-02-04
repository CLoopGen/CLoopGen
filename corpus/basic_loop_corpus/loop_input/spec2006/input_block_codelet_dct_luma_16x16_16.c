#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int InvLevelScale4x4Luma_Intra[6][4][4];
int i;
int j;
int _usr_j1;
int M4[4][4];
int M5[4];
int M6[4];
int M0[4][4][4][4];
int qp_per;
int qp_rem;
Boolean lossless_qpprime;

void init_vars() {
    // Initialize InvLevelScale4x4Luma_Intra with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 6; idx++) {
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                InvLevelScale4x4Luma_Intra[idx][y][x] = (idx + 1) * 8;
            }
        }
    }

    // Initialize M4 with sequential data
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            M4[y][x] = (y * 4 + x) + 1;
        }
    }

    // Initialize scaling parameters to ensure the loop runs and performs shifts safely
    qp_per = 5;      // Triggers the first branch (qp_per < 6)
    qp_rem = 3;      // Index within [0,5] range

    // Set lossless_qpprime to FALSE so the outer loop executes
    lossless_qpprime = FALSE;

    // Zero out M0 to prevent undefined behavior on partial writes
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    M0[a][b][c][d] = 0;
                }
            }
        }
    }

    // Initialize scalar temporaries
    i = 0;
    j = 0;
    _usr_j1 = 0;

    // Initialize M5 and M6 (will be overwritten in loop, but zero-initialize for safety)
    for (int idx = 0; idx < 4; idx++) {
        M5[idx] = 0;
        M6[idx] = 0;
    }
}