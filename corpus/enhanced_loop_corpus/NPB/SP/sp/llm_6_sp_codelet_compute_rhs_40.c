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
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 1];
            wm1 = ws[i][j][k - 1];
            double u0kp1 = u[0][i][j][k + 1];
            double u0k   = u[0][i][j][k];
            double u0km1 = u[0][i][j][k - 1];
            double diff0 = u0kp1 - 2. * u0k + u0km1;
            double grad3 = u[3][i][j][k + 1] - u[3][i][j][k - 1];
            rhs[0][i][j][k] += dz1tz1 * diff0 - tz2 * grad3;

            double u1kp1 = u[1][i][j][k + 1];
            double u1k   = u[1][i][j][k];
            double u1km1 = u[1][i][j][k - 1];
            double uskp1 = us[i][j][k + 1];
            double usk   = us[i][j][k];
            double uskm1 = us[i][j][k - 1];
            double diff1 = u1kp1 - 2. * u1k + u1km1;
            double diffus = uskp1 - 2. * usk + uskm1;
            double adv1 = u1kp1 * wp1 - u1km1 * wm1;
            rhs[1][i][j][k] += dz2tz1 * diff1 + zzcon2 * diffus - tz2 * adv1;

            double vskp1 = vs[i][j][k + 1];
            double vsk   = vs[i][j][k];
            double vskm1 = vs[i][j][k - 1];
            double diffvs = vskp1 - 2. * vsk + vskm1;
            rhs[2][i][j][k] += dz3tz1 * (u[2][i][j][k + 1] - 2. * u[2][i][j][k] + u[2][i][j][k - 1]) 
                             + zzcon2 * diffvs 
                             - tz2 * (u[2][i][j][k + 1] * wp1 - u[2][i][j][k - 1] * wm1);

            double up4kp1 = u[4][i][j][k + 1];
            double up4km1 = u[4][i][j][k - 1];
            double sqp1 = square[i][j][k + 1];
            double sqm1 = square[i][j][k - 1];
            rhs[3][i][j][k] += dz4tz1 * (u[3][i][j][k + 1] - 2. * u[3][i][j][k] + u[3][i][j][k - 1]) 
                             + zzcon2 * con43 * (wp1 - 2. * wijk + wm1)
                             - tz2 * (u[3][i][j][k + 1] * wp1 - u[3][i][j][k - 1] * wm1 
                                      + (up4kp1 - sqp1 - up4km1 + sqm1) * c2);

            double qsp1 = qs[i][j][k + 1];
            double qsk  = qs[i][j][k];
            double qsm1 = qs[i][j][k - 1];
            double rhop1 = rho_i[i][j][k + 1];
            double rhok  = rho_i[i][j][k];
            double rhom1 = rho_i[i][j][k - 1];
            rhs[4][i][j][k] += dz5tz1 * (u[4][i][j][k + 1] - 2. * u[4][i][j][k] + u[4][i][j][k - 1])
                             + zzcon3 * (qsp1 - 2. * qsk + qsm1)
                             + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1)
                             + zzcon5 * (up4kp1 * rhop1 - 2. * u[4][i][j][k] * rhok + up4km1 * rhom1)
                             - tz2 * ((c1 * up4kp1 - c2 * sqp1) * wp1 - (c1 * up4km1 - c2 * sqm1) * wm1);
        }
    }
}
}
