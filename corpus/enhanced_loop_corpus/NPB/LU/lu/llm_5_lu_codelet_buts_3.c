#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double tv[64][64][5];
extern double d[64][64][5][5];
extern double udx[64][64][5][5];
extern double udy[64][64][5][5];
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
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        // Compute tv update in unrolled fashion with early exit condition
        double sum[5] = {0};
        int valid = 1;

        for (m = 0; m < 5 && valid; m++) {
            double term = 0;
            for (int n = 0; n < 5; n++) {
                term += udy[i][j][m][n] * v[i][j + 1][k][n] + udx[i][j][m][n] * v[i + 1][j][k][n];
            }
            tv[i][j][m] += omega * term;

            // Check for invalid input as a control dependency trigger
            if (tv[i][j][m] != tv[i][j][m]) {  // NaN check
                valid = 0;
            }
        }

        // Only proceed with matrix operations if data is valid
        if (!valid) continue;

        // Load transformation matrix
        for (m = 0; m < 5; m++) {
            for (int n = 0; n < 5; n++) {
                tmat[m][n] = d[i][j][m][n];
            }
        }

        // Forward elimination with explicit per-row conditions
        tmp1 = tmat[0][0];
        if (tmp1 == 0.0) {
            tv[i][j][0] = 0.0;
            tv[i][j][1] = 0.0;
            tv[i][j][2] = 0.0;
            tv[i][j][3] = 0.0;
            tv[i][j][4] = 0.0;
        } else {
            tmp1 = 1.0 / tmp1;

            // Eliminate column 0
            tmp = tmp1 * tmat[1][0]; tmat[1][1] -= tmp * tmat[0][1]; tmat[1][2] -= tmp * tmat[0][2]; tmat[1][3] -= tmp * tmat[0][3]; tmat[1][4] -= tmp * tmat[0][4]; tv[i][j][1] -= tv[i][j][0] * tmp;
            tmp = tmp1 * tmat[2][0]; tmat[2][1] -= tmp * tmat[0][1]; tmat[2][2] -= tmp * tmat[0][2]; tmat[2][3] -= tmp * tmat[0][3]; tmat[2][4] -= tmp * tmat[0][4]; tv[i][j][2] -= tv[i][j][0] * tmp;
            tmp = tmp1 * tmat[3][0]; tmat[3][1] -= tmp * tmat[0][1]; tmat[3][2] -= tmp * tmat[0][2]; tmat[3][3] -= tmp * tmat[0][3]; tmat[3][4] -= tmp * tmat[0][4]; tv[i][j][3] -= tv[i][j][0] * tmp;
            tmp = tmp1 * tmat[4][0]; tmat[4][1] -= tmp * tmat[0][1]; tmat[4][2] -= tmp * tmat[0][2]; tmat[4][3] -= tmp * tmat[0][3]; tmat[4][4] -= tmp * tmat[0][4]; tv[i][j][4] -= tv[i][j][0] * tmp;

            // Column 1
            tmp1 = tmat[1][1];
            if (tmp1 == 0.0) goto finalize;
            tmp1 = 1.0 / tmp1;

            tmp = tmp1 * tmat[2][1]; tmat[2][2] -= tmp * tmat[1][2]; tmat[2][3] -= tmp * tmat[1][3]; tmat[2][4] -= tmp * tmat[1][4]; tv[i][j][2] -= tv[i][j][1] * tmp;
            tmp = tmp1 * tmat[3][1]; tmat[3][2] -= tmp * tmat[1][2]; tmat[3][3] -= tmp * tmat[1][3]; tmat[3][4] -= tmp * tmat[1][4]; tv[i][j][3] -= tv[i][j][1] * tmp;
            tmp = tmp1 * tmat[4][1]; tmat[4][2] -= tmp * tmat[1][2]; tmat[4][3] -= tmp * tmat[1][3]; tmat[4][4] -= tmp * tmat[1][4]; tv[i][j][4] -= tv[i][j][1] * tmp;

            // Column 2
            tmp1 = tmat[2][2];
            if (tmp1 == 0.0) goto finalize;
            tmp1 = 1.0 / tmp1;

            tmp = tmp1 * tmat[3][2]; tmat[3][3] -= tmp * tmat[2][3]; tmat[3][4] -= tmp * tmat[2][4]; tv[i][j][3] -= tv[i][j][2] * tmp;
            tmp = tmp1 * tmat[4][2]; tmat[4][3] -= tmp * tmat[2][3]; tmat[4][4] -= tmp * tmat[2][4]; tv[i][j][4] -= tv[i][j][2] * tmp;

            // Column 3
            tmp1 = tmat[3][3];
            if (tmp1 == 0.0) goto finalize;
            tmp1 = 1.0 / tmp1;

            tmp = tmp1 * tmat[4][3]; tmat[4][4] -= tmp * tmat[3][4]; tv[i][j][4] -= tv[i][j][3] * tmp;

finalize:
            // Back-substitute only if all pivots were non-zero
            if (tmat[4][4] != 0.0) tv[i][j][4] /= tmat[4][4];
            if (tmat[3][3] != 0.0) tv[i][j][3] = (tv[i][j][3] - tmat[3][4] * tv[i][j][4]) / tmat[3][3];
            if (tmat[2][2] != 0.0) tv[i][j][2] = (tv[i][j][2] - tmat[2][3] * tv[i][j][3] - tmat[2][4] * tv[i][j][4]) / tmat[2][2];
            if (tmat[1][1] != 0.0) tv[i][j][1] = (tv[i][j][1] - tmat[1][2] * tv[i][j][2] - tmat[1][3] * tv[i][j][3] - tmat[1][4] * tv[i][j][4]) / tmat[1][1];
            if (tmat[0][0] != 0.0) tv[i][j][0] = (tv[i][j][0] - tmat[0][1] * tv[i][j][1] - tmat[0][2] * tv[i][j][2] - tmat[0][3] * tv[i][j][3] - tmat[0][4] * tv[i][j][4]) / tmat[0][0];
        }

        // Final correction to v
        v[i][j][k][0] -= tv[i][j][0];
        v[i][j][k][1] -= tv[i][j][1];
        v[i][j][k][2] -= tv[i][j][2];
        v[i][j][k][3] -= tv[i][j][3];
        v[i][j][k][4] -= tv[i][j][4];
    }
}
}
