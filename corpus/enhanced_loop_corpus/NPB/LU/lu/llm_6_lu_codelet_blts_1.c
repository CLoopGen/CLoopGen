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
        // Introduce temporary arrays to remove immediate write-after-write (WAW) and write-after-read (WAR)
        // dependencies by decoupling updates to v[i][j][k][m] until the end.
        double v_local[5];
        double tmat[5][5];
        
        // First, load current v values into local storage to reduce memory dependency
        for (m = 0; m < 5; m++) {
            v_local[m] = v[i][j][k][m];
        }

        // Compute update using neighbor values but store result in local buffer
        for (m = 0; m < 5; m++) {
            v_local[m] = v_local[m] - omega * (
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
        }

        // Copy d[i][j] to tmat locally — no change in logic
        for (m = 0; m < 5; m++) {
            tmat[m][0] = d[i][j][m][0];
            tmat[m][1] = d[i][j][m][1];
            tmat[m][2] = d[i][j][m][2];
            tmat[m][3] = d[i][j][m][3];
            tmat[m][4] = d[i][j][m][4];
        }

        // Forward elimination with reduced memory interference via local tmat and v_local
        double tmp1 = 1.0 / tmat[0][0];
        for (int n = 1; n < 5; n++) {
            double tmp = tmp1 * tmat[n][0];
            v_local[n] -= v_local[0] * tmp;
            for (int p = 1; p < 5; p++) {
                tmat[n][p] -= tmp * tmat[0][p];
            }
        }

        tmp1 = 1.0 / tmat[1][1];
        for (int n = 2; n < 5; n++) {
            double tmp = tmp1 * tmat[n][1];
            v_local[n] -= v_local[1] * tmp;
            for (int p = 2; p < 5; p++) {
                tmat[n][p] -= tmp * tmat[1][p];
            }
        }

        tmp1 = 1.0 / tmat[2][2];
        for (int n = 3; n < 5; n++) {
            double tmp = tmp1 * tmat[n][2];
            v_local[n] -= v_local[2] * tmp;
            for (int p = 3; p < 5; p++) {
                tmat[n][p] -= tmp * tmat[2][p];
            }
        }

        tmp1 = 1.0 / tmat[3][3];
        double tmp = tmp1 * tmat[4][3];
        v_local[4] -= v_local[3] * tmp;
        tmat[4][4] -= tmp * tmat[3][4];

        // Back substitution using local data
        v_local[4] /= tmat[4][4];
        v_local[3] = (v_local[3] - tmat[3][4] * v_local[4]) / tmat[3][3];
        v_local[2] = (v_local[2] - tmat[2][3] * v_local[3] - tmat[2][4] * v_local[4]) / tmat[2][2];
        v_local[1] = (v_local[1] - tmat[1][2] * v_local[2] - tmat[1][3] * v_local[3] - tmat[1][4] * v_local[4]) / tmat[1][1];
        v_local[0] = (v_local[0] - tmat[0][1] * v_local[1] - tmat[0][2] * v_local[2] - tmat[0][3] * v_local[3] - tmat[0][4] * v_local[4]) / tmat[0][0];

        // Final write-back to global memory: eliminates WAW and WAR hazards during computation
        for (m = 0; m < 5; m++) {
            v[i][j][k][m] = v_local[m];
        }
    }
}
}
