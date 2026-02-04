#include <stdio.h>

extern  int ny;
extern  int nz;
extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double ty1;
extern  double ty2;
extern  double ty3;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double rsd[64][65][65][5];
extern  double frct[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int L2;
extern int jst1;
extern int jend1;
extern double dsspm;
extern double tmp;
extern double u21j;
extern double u31j;
extern double u41j;
extern double u51j;
extern double u21jm1;
extern double u31jm1;
extern double u41jm1;
extern double u51jm1;



void loop(){
for (i = ist; i <= iend; i++) {
    for (k = 1; k <= nz - 2; k++) {
        // Reorder computation: combine flux and frct updates to create new RAW dependencies
        // Precompute normalized variables earlier and store locally to reduce memory traffic
        double u21[65], u31[65], u41[65], u51[65];
        double tmp_inv[65];

        for (j = jst - 1; j <= jend + 1; j++) {
            if (j >= 1 && j <= ny) {
                tmp_inv[j] = 1.0 / rsd[i][j][k][0];
                u21[j] = tmp_inv[j] * rsd[i][j][k][1];
                u31[j] = tmp_inv[j] * rsd[i][j][k][2];
                u41[j] = tmp_inv[j] * rsd[i][j][k][3];
                u51[j] = tmp_inv[j] * rsd[i][j][k][4];
            }
        }

        // Compute flux based on pre-fetched u values — removes repeated division
        for (j = jst; j <= L2; j++) {
            double du2 = u21[j] - u21[j-1];
            double du3 = u31[j] - u31[j-1];
            double du4 = u41[j] - u41[j-1];
            double du5 = u51[j] - u51[j-1];

            double v2_j = u21[j]*u21[j] + u31[j]*u31[j] + u41[j]*u41[j];
            double v2_jm1 = u21[j-1]*u21[j-1] + u31[j-1]*u31[j-1] + u41[j-1]*u41[j-1];

            flux[i][j][k][1] = ty3 * du2;
            flux[i][j][k][2] = (4.0/3.0) * ty3 * du3;
            flux[i][j][k][3] = ty3 * du4;
            flux[i][j][k][4] = 0.5*(1.0 - 1.96) * ty3 * (v2_j - v2_jm1) +
                               (1.0/6.0)*ty3*(u31[j]*u31[j] - u31[j-1]*u31[j-1]) +
                               1.96 * ty3 * du5;
        }

        // Update frct with fused difference and smoothing operations
        // Introduce artificial loop-carried dependency via accumulator to simulate reduction-like behavior
        double acc[5] = {0};
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                double diff_flux = flux[i][j+1][k][m] - flux[i][j-1][k][m];
                frct[i][j][k][m] = frct[i][j][k][m] - ty2 * diff_flux;

                // Add accumulating term to create WAR dependency across j
                acc[m] += frct[i][j][k][m];
                frct[i][j][k][m] = acc[m]; // Write after read from previous j
            }
        }

        // Reverse the diffusion update to change direction of data flow
        for (j = jend; j >= jst; j--) {
            frct[i][j][k][0] += dy1 * ty1 * (rsd[i][j-1][k][0] - 2.*rsd[i][j][k][0] + rsd[i][j+1][k][0]);
            frct[i][j][k][1] += ty3 * 0.1 * (flux[i][j+1][k][1] - flux[i][j][k][1]) + dy2 * ty1 * (rsd[i][j-1][k][1] - 2.*rsd[i][j][k][1] + rsd[i][j+1][k][1]);
            frct[i][j][k][2] += ty3 * 0.1 * (flux[i][j+1][k][2] - flux[i][j][k][2]) + dy3 * ty1 * (rsd[i][j-1][k][2] - 2.*rsd[i][j][k][2] + rsd[i][j+1][k][2]);
            frct[i][j][k][3] += ty3 * 0.1 * (flux[i][j+1][k][3] - flux[i][j][k][3]) + dy4 * ty1 * (rsd[i][j-1][k][3] - 2.*rsd[i][j][k][3] + rsd[i][j+1][k][3]);
            frct[i][j][k][4] += ty3 * 0.1 * (flux[i][j+1][k][4] - flux[i][j][k][4]) + dy5 * ty1 * (rsd[i][j-1][k][4] - 2.*rsd[i][j][k][4] + rsd[i][j+1][k][4]);
        }

        // Smoothing operations now use indirect indexing to obscure stride access
        int indices[] = {1, 2, ny-3, ny-2};
        for (int idx = 0; idx < 4; idx++) {
            j = indices[idx];
            for (m = 0; m < 5; m++) {
                if (j == 1) {
                    frct[i][j][k][m] -= dsspm * (+5.*rsd[i][j][k][m] - 4.*rsd[i][j+1][k][m] + rsd[i][j+2][k][m]);
                } else if (j == 2) {
                    frct[i][j][k][m] -= dsspm * (-4.*rsd[i][j-1][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j+1][k][m] + rsd[i][j+2][k][m]);
                } else if (j == ny-3) {
                    frct[i][j][k][m] -= dsspm * (rsd[i][j-2][k][m] - 4.*rsd[i][j-1][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j+1][k][m]);
                } else if (j == ny-2) {
                    frct[i][j][k][m] -= dsspm * (rsd[i][j-2][k][m] - 4.*rsd[i][j-1][k][m] + 5.*rsd[i][j][k][m]);
                }
            }
        }

        // Inner smooth region now computed with unrolled j-steps to increase reuse
        jst1 = 3;
        jend1 = ny - 4;
        for (j = jst1 + 2; j <= jend1 - 2; j += 3) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m]   -= dsspm * (rsd[i][j-2][k][m] - 4.*rsd[i][j-1][k][m] + 6.*rsd[i][j][k][m] - 4.*rsd[i][j+1][k][m] + rsd[i][j+2][k][m]);
                if (j+1 <= jend1) {
                    frct[i][j+1][k][m] -= dsspm * (rsd[i][j-1][k][m] - 4.*rsd[i][j][k][m] + 6.*rsd[i][j+1][k][m] - 4.*rsd[i][j+2][k][m] + rsd[i][j+3][k][m]);
                }
                if (j+2 <= jend1) {
                    frct[i][j+2][k][m] -= dsspm * (rsd[i][j][k][m]   - 4.*rsd[i][j+1][k][m] + 6.*rsd[i][j+2][k][m] - 4.*rsd[i][j+3][k][m] + rsd[i][j+4][k][m]);
                }
            }
        }
    }
}
}
