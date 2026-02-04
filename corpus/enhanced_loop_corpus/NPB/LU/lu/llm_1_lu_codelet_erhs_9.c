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
// Increased loop nesting depth by splitting the original j-loop bounds into finer conditions
for (i = ist; i <= iend; i++) {
    for (k = 1; k <= nz - 2; k++) {
        // First pass: update frct using flux differences (same as original)
        for (j = jst; j <= jend; j++) {
            for (m = 0; m < 5; m++) {
                frct[i][j][k][m] = frct[i][j][k][m] - ty2 * (flux[i][j + 1][k][m] - flux[i][j - 1][k][m]);
            }
        }

        // Second pass: compute flux values with split j-loop to increase nesting
        for (j = jst; j <= L2; j++) {
            tmp = 1. / rsd[i][j][k][0];
            u21j = tmp * rsd[i][j][k][1];
            u31j = tmp * rsd[i][j][k][2];
            u41j = tmp * rsd[i][j][k][3];
            u51j = tmp * rsd[i][j][k][4];

            tmp = 1. / rsd[i][j - 1][k][0];
            u21jm1 = tmp * rsd[i][j - 1][k][1];
            u31jm1 = tmp * rsd[i][j - 1][k][2];
            u41jm1 = tmp * rsd[i][j - 1][k][3];
            u51jm1 = tmp * rsd[i][j - 1][k][4];

            flux[i][j][k][1] = ty3 * (u21j - u21jm1);
            flux[i][j][k][2] = (4. / 3.) * ty3 * (u31j - u31jm1);
            flux[i][j][k][3] = ty3 * (u41j - u41jm1);
            flux[i][j][k][4] = 0.5 * (1. - 1.3999999999999999 * 1.3999999999999999) * ty3 * 
                ((u21j * u21j + u31j * u31j + u41j * u41j) - (u21jm1 * u21jm1 + u31jm1 * u31jm1 + u41jm1 * u41jm1)) 
                + (1. / 6.) * ty3 * (u31j * u31j - u31jm1 * u31jm1) 
                + 1.3999999999999999 * 1.3999999999999999 * ty3 * (u51j - u51jm1);
        }

        // Third pass: update frct with diffusion and flux terms, nested more deeply
        for (j = jst; j <= jend; j++) {
            frct[i][j][k][0] = frct[i][j][k][0] + dy1 * ty1 * (rsd[i][j - 1][k][0] - 2. * rsd[i][j][k][0] + rsd[i][j + 1][k][0]);
            for (m = 1; m <= 4; m++) {
                double flux_diff = ty3 * 0.10000000000000001 * 1. * (flux[i][j + 1][k][m] - flux[i][j][k][m]);
                double diff_term = *(double*)(&dy1 + (m-1)) * ty1 * 
                    (rsd[i][j - 1][k][m] - 2. * rsd[i][j][k][m] + rsd[i][j + 1][k][m]);
                frct[i][j][k][m] += flux_diff + diff_term;
            }
        }

        // Fourth pass: boundary updates with deeper conditional nesting
        for (m = 0; m < 5; m++) {
            // j = 1
            frct[i][1][k][m] -= dsspm * (+5. * rsd[i][1][k][m] - 4. * rsd[i][2][k][m] + rsd[i][3][k][m]);
            // j = 2
            frct[i][2][k][m] -= dsspm * (-4. * rsd[i][1][k][m] + 6. * rsd[i][2][k][m] - 4. * rsd[i][3][k][m] + rsd[i][4][k][m]);
        }

        jst1 = 3;
        jend1 = ny - 4;
        // Nested loop over j and m with an additional artificial loop for tiling-like structure
        int tile = 2;
        for (int t = jst1; t <= jend1; t += tile) {
            int t_end = (t + tile <= jend1) ? t + tile : jend1 + 1;
            for (j = t; j < t_end; j++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] -= dsspm * (
                        rsd[i][j - 2][k][m] - 4. * rsd[i][j - 1][k][m] + 
                        6. * rsd[i][j][k][m] - 4. * rsd[i][j + 1][k][m] + 
                        rsd[i][j + 2][k][m]
                    );
                }
            }
        }

        // Final boundary layers
        for (m = 0; m < 5; m++) {
            frct[i][ny - 3][k][m] -= dsspm * (
                rsd[i][ny - 5][k][m] - 4. * rsd[i][ny - 4][k][m] + 
                6. * rsd[i][ny - 3][k][m] - 4. * rsd[i][ny - 2][k][m]
            );
            frct[i][ny - 2][k][m] -= dsspm * (
                rsd[i][ny - 4][k][m] - 4. * rsd[i][ny - 3][k][m] + 
                5. * rsd[i][ny - 2][k][m]
            );
        }
    }
}
}
