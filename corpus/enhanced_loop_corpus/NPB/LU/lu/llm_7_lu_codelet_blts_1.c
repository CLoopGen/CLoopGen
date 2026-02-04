#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double ldy[64][64][5][5];
extern double ldx[64][64][5][5];
extern double d[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;
extern double tmp;
extern double tmp1;
extern double tmat[5][5];



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        // Variant that increases loop-carried dependence by reordering operations
        // and introducing artificial sequential dependencies across m-loop
        double tmat[5][5];
        double v_temp[5];

        // Initialize tmat from d[i][j], but now do it element-wise with forced ordering
        for (m = 0; m < 5; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }

        // Introduce strong loop-carried dependency: process m sequentially with cumulative updates
        // First modify v[i][j][k][m] using neighbor terms — keep this as is but make it affect next m
        for (m = 0; m < 5; m++) {
            // This creates a RAW hazard: each m depends on previous computations
            if (m == 0) {
                v_temp[m] = v[i][j][k][m] - omega * (
                    ldy[i][j][m][0] * v[i][j-1][k][0] +
                    ldx[i][j][m][0] * v[i-1][j][k][0] +
                    ldy[i][j][m][1] * v[i][j-1][k][1] +
                    ldx[i][j][m][1] * v[i-1][j][k][1] +
                    ldy[i][j][m][2] * v[i][j-1][k][2] +
                    ldx[i][j][m][2] * v[i-1][j][k][2] +
                    ldy[i][j][m][3] * v[i][j-1][k][3] +
                    ldx[i][j][m][3] * v[i-1][j][k][3] +
                    ldy[i][j][m][4] * v[i][j-1][k][4] +
                    ldx[i][j][m][4] * v[i-1][j][k][4]
                );
            } else {
                // Artificially create dependency on prior m: use updated v_temp[m-1] to influence current
                v_temp[m] = v[i][j][k][m] - omega * (
                    ldy[i][j][m][0] * v[i][j-1][k][0] +
                    ldx[i][j][m][0] * v[i-1][j][k][0] +
                    ldy[i][j][m][1] * v[i][j-1][k][1] +
                    ldx[i][j][m][1] * v[i-1][j][k][1] +
                    ldy[i][j][m][2] * v[i][j-1][k][2] +
                    ldx[i][j][m][2] * v[i-1][j][k][2] +
                    ldy[i][j][m][3] * v[i][j-1][k][3] +
                    ldx[i][j][m][3] * v[i-1][j][k][3] +
                    ldy[i][j][m][4] * v[i][j-1][k][4] +
                    ldx[i][j][m][4] * v[i-1][j][k][4]
                ) + 0.01 * v_temp[m-1]; // Artificial RAW dependency on previous m
            }
        }

        // Copy modified v_temp back to v only after full m loop
        for (m = 0; m < 5; m++) {
            v[i][j][k][m] = v_temp[m];
        }

        // Now perform LU-style elimination with enforced sequentiality via unrolled loops
        // But now we introduce WAR by writing tmat early and reading later
        double tmp1 = 1.0 / tmat[0][0];
        double tmp;

        tmp = tmp1 * tmat[1][0];
        tmat[1][1] -= tmp * tmat[0][1];
        tmat[1][2] -= tmp * tmat[0][2];
        tmat[1][3] -= tmp * tmat[0][3];
        tmat[1][4] -= tmp * tmat[0][4];
        v[i][j][k][1] -= v[i][j][k][0] * tmp;

        tmp = tmp1 * tmat[2][0];
        tmat[2][1] -= tmp * tmat[0][1];  // Read after write of tmat[0][*] -> safe
        tmat[2][2] -= tmp * tmat[0][2];
        tmat[2][3] -= tmp * tmat[0][3];
        tmat[2][4] -= tmp * tmat[0][4];
        v[i][j][k][2] -= v[i][j][k][0] * tmp;

        tmp = tmp1 * tmat[3][0];
        tmat[3][1] -= tmp * tmat[0][1];
        tmat[3][2] -= tmp * tmat[0][2];
        tmat[3][3] -= tmp * tmat[0][3];
        tmat[3][4] -= tmp * tmat[0][4];
        v[i][j][k][3] -= v[i][j][k][0] * tmp;

        tmp = tmp1 * tmat[4][0];
        tmat[4][1] -= tmp * tmat[0][1];
        tmat[4][2] -= tmp * tmat[0][2];
        tmat[4][3] -= tmp * tmat[0][3];
        tmat[4][4] -= tmp * tmat[0][4];
        v[i][j][k][4] -= v[i][j][k][0] * tmp;

        tmp1 = 1.0 / tmat[1][1];
        tmp = tmp1 * tmat[2][1];
        tmat[2][2] -= tmp * tmat[1][2];
        tmat[2][3] -= tmp * tmat[1][3];
        tmat[2][4] -= tmp * tmat[1][4];
        v[i][j][k][2] -= v[i][j][k][1] * tmp;

        tmp = tmp1 * tmat[3][1];
        tmat[3][2] -= tmp * tmat[1][2];
        tmat[3][3] -= tmp * tmat[1][3];
        tmat[3][4] -= tmp * tmat[1][4];
        v[i][j][k][3] -= v[i][j][k][1] * tmp;

        tmp = tmp1 * tmat[4][1];
        tmat[4][2] -= tmp * tmat[1][2];
        tmat[4][3] -= tmp * tmat[1][3];
        tmat[4][4] -= tmp * tmat[1][4];
        v[i][j][k][4] -= v[i][j][k][1] * tmp;

        tmp1 = 1.0 / tmat[2][2];
        tmp = tmp1 * tmat[3][2];
        tmat[3][3] -= tmp * tmat[2][3];
        tmat[3][4] -= tmp * tmat[2][4];
        v[i][j][k][3] -= v[i][j][k][2] * tmp;

        tmp = tmp1 * tmat[4][2];
        tmat[4][3] -= tmp * tmat[2][3];
        tmat[4][4] -= tmp * tmat[2][4];
        v[i][j][k][4] -= v[i][j][k][2] * tmp;

        tmp1 = 1.0 / tmat[3][3];
        tmp = tmp1 * tmat[4][3];
        tmat[4][4] -= tmp * tmat[3][4];
        v[i][j][k][4] -= v[i][j][k][3] * tmp;

        // Final solve step — introduces WAW if not serialized properly
        v[i][j][k][4] /= tmat[4][4];
        v[i][j][k][3] = (v[i][j][k][3] - tmat[3][4] * v[i][j][k][4]) / tmat[3][3];
        v[i][j][k][2] = (v[i][j][k][2] - tmat[2][3] * v[i][j][k][3] - tmat[2][4] * v[i][j][k][4]) / tmat[2][2];
        v[i][j][k][1] = (v[i][j][k][1] - tmat[1][2] * v[i][j][k][2] - tmat[1][3] * v[i][j][k][3] - tmat[1][4] * v[i][j][k][4]) / tmat[1][1];
        v[i][j][k][0] = (v[i][j][k][0] - tmat[0][1] * v[i][j][k][1] - tmat[0][2] * v[i][j][k][2] - tmat[0][3] * v[i][j][k][3] - tmat[0][4] * v[i][j][k][4]) / tmat[0][0];
    }
}
}
