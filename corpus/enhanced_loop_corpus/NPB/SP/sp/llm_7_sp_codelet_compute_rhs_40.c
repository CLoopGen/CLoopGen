#include <stdio.h>

extern  int grid_points[3];
extern  double tz2;
extern  double zzcon2;
extern  double zzcon3;
extern  double zzcon4;
extern  double zzcon5;
extern  double dz1tz1;
extern  double dz2tz1;
extern  double dz3tz1;
extern  double dz4tz1;
extern  double dz5tz1;
extern  double c1;
extern  double c2;
extern  double con43;
extern  double u[5][65][65][65];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double wijk;
extern double wp1;
extern double wm1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i += 2) {
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 1];
            wm1 = ws[i][j][k - 1];

            double lapu0 = u[0][i][j][k + 1] - 2.0 * u[0][i][j][k] + u[0][i][j][k - 1];
            double gradu3 = u[3][i][j][k + 1] - u[3][i][j][k - 1];
            rhs[0][i][j][k] += dz1tz1 * lapu0 - tz2 * gradu3;

            double lapu1 = u[1][i][j][k + 1] - 2.0 * u[1][i][j][k] + u[1][i][j][k - 1];
            double lapus = us[i][j][k + 1] - 2.0 * us[i][j][k] + us[i][j][k - 1];
            double advu1 = u[1][i][j][k + 1] * wp1 - u[1][i][j][k - 1] * wm1;
            rhs[1][i][j][k] += dz2tz1 * lapu1 + zzcon2 * lapus - tz2 * advu1;

            double lapu2 = u[2][i][j][k + 1] - 2.0 * u[2][i][j][k] + u[2][i][j][k - 1];
            double lapvs = vs[i][j][k + 1] - 2.0 * vs[i][j][k] + vs[i][j][k - 1];
            double advu2 = u[2][i][j][k + 1] * wp1 - u[2][i][j][k - 1] * wm1;
            rhs[2][i][j][k] += dz3tz1 * lapu2 + zzcon2 * lapvs - tz2 * advu2;

            double lapu3 = u[3][i][j][k + 1] - 2.0 * u[3][i][j][k] + u[3][i][j][k - 1];
            double lapw = wp1 - 2.0 * wijk + wm1;
            double term3a = u[3][i][j][k + 1] * wp1 - u[3][i][j][k - 1] * wm1;
            double term3b = (u[4][i][j][k + 1] - square[i][j][k + 1] - u[4][i][j][k - 1] + square[i][j][k - 1]) * c2;
            rhs[3][i][j][k] += dz4tz1 * lapu3 + zzcon2 * con43 * lapw - tz2 * (term3a + term3b);

            double lapu4 = u[4][i][j][k + 1] - 2.0 * u[4][i][j][k] + u[4][i][j][k - 1];
            double lapqs = qs[i][j][k + 1] - 2.0 * qs[i][j][k] + qs[i][j][k - 1];
            double lapww = wp1 * wp1 - 2.0 * wijk * wijk + wm1 * wm1;
            double lappi = u[4][i][j][k + 1] * rho_i[i][j][k + 1] - 2.0 * u[4][i][j][k] * rho_i[i][j][k] + u[4][i][j][k - 1] * rho_i[i][j][k - 1];
            double term4a = (c1 * u[4][i][j][k + 1] - c2 * square[i][j][k + 1]) * wp1;
            double term4b = (c1 * u[4][i][j][k - 1] - c2 * square[i][j][k - 1]) * wm1;
            rhs[4][i][j][k] += dz5tz1 * lapu4 + zzcon3 * lapqs + zzcon4 * lapww + zzcon5 * lappi - tz2 * (term4a - term4b);

            if (i+1 < grid_points[0]-1 && j+1 < grid_points[1]-1 && k+1 < grid_points[2]-1) {
                int i2 = i+1, j2 = j+1, k2 = k+1;
                double w2 = ws[i2][j2][k2];
                double wp2 = ws[i2][j2][k2+1];
                double wm2 = ws[i2][j2][k2-1];
                rhs[0][i2][j2][k2] += dz1tz1 * (u[0][i2][j2][k2+1] - 2.*u[0][i2][j2][k2] + u[0][i2][j2][k2-1]) 
                                    - tz2 * (u[3][i2][j2][k2+1] - u[3][i2][j2][k2-1]);
                rhs[1][i2][j2][k2] += dz2tz1 * (u[1][i2][j2][k2+1] - 2.*u[1][i2][j2][k2] + u[1][i2][j2][k2-1]) 
                                    + zzcon2 * (us[i2][j2][k2+1] - 2.*us[i2][j2][k2] + us[i2][j2][k2-1]) 
                                    - tz2 * (u[1][i2][j2][k2+1]*wp2 - u[1][i2][j2][k2-1]*wm2);
                rhs[2][i2][j2][k2] += dz3tz1 * (u[2][i2][j2][k2+1] - 2.*u[2][i2][j2][k2] + u[2][i2][j2][k2-1]) 
                                    + zzcon2 * (vs[i2][j2][k2+1] - 2.*vs[i2][j2][k2] + vs[i2][j2][k2-1]) 
                                    - tz2 * (u[2][i2][j2][k2+1]*wp2 - u[2][i2][j2][k2-1]*wm2);
                rhs[3][i2][j2][k2] += dz4tz1 * (u[3][i2][j2][k2+1] - 2.*u[3][i2][j2][k2] + u[3][i2][j2][k2-1]) 
                                    + zzcon2 * con43 * (wp2 - 2.*w2 + wm2)
                                    - tz2 * (u[3][i2][j2][k2+1]*wp2 - u[3][i2][j2][k2-1]*wm2 
                                             + (u[4][i2][j2][k2+1] - square[i2][j2][k2+1] - u[4][i2][j2][k2-1] + square[i2][j2][k2-1]) * c2);
                rhs[4][i2][j2][k2] += dz5tz1 * (u[4][i2][j2][k2+1] - 2.*u[4][i2][j2][k2] + u[4][i2][j2][k2-1]) 
                                    + zzcon3 * (qs[i2][j2][k2+1] - 2.*qs[i2][j2][k2] + qs[i2][j2][k2-1])
                                    + zzcon4 * (wp2*wp2 - 2.*w2*w2 + wm2*wm2)
                                    + zzcon5 * (u[4][i2][j2][k2+1]*rho_i[i2][j2][k2+1] - 2.*u[4][i2][j2][k2]*rho_i[i2][j2][k2] + u[4][i2][j2][k2-1]*rho_i[i2][j2][k2-1])
                                    - tz2 * ((c1*u[4][i2][j2][k2+1] - c2*square[i2][j2][k2+1])*wp2 - (c1*u[4][i2][j2][k2-1] - c2*square[i2][j2][k2-1])*wm2);
            }
        }
    }
}
}
