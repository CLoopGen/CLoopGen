#include <stdio.h>

extern  int ist;
extern  int iend;
extern  int jst;
extern  int jend;
extern  double tx1;
extern  double tx2;
extern  double ty1;
extern  double ty2;
extern  double tz1;
extern  double tz2;
extern  double dx1;
extern  double dx2;
extern  double dx3;
extern  double dx4;
extern  double dx5;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
extern  double u[64][65][65][5];
extern  double dt;
extern  double a[64][64][5][5];
extern  double b[64][64][5][5];
extern  double c[64][64][5][5];
extern  double d[64][64][5][5];
extern int k;
extern int i;
extern int j;
extern double r43;
extern double c1345;
extern double c34;
extern double tmp1;
extern double tmp2;
extern double tmp3;



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        double tmp1_k = 1. / u[i][j][k][0];
        double tmp2_k = tmp1_k * tmp1_k;
        double tmp3_k = tmp1_k * tmp2_k;
        
        d[i][j][0][0] = 1. + dt * 2. * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
        d[i][j][0][1] = 0.;
        d[i][j][0][2] = 0.;
        d[i][j][0][3] = 0.;
        d[i][j][0][4] = 0.;

        double term1_1 = dt * 2. * (tx1 * (-r43 * c34 * tmp2_k * u[i][j][k][1]) + 
                                   ty1 * (-c34 * tmp2_k * u[i][j][k][1]) + 
                                   tz1 * (-c34 * tmp2_k * u[i][j][k][1]));
        double term1_2 = 1. + dt * 2. * (tx1 * r43 * c34 * tmp1_k + 
                                         ty1 * c34 * tmp1_k + 
                                         tz1 * c34 * tmp1_k) + 
                         dt * 2. * (tx1 * dx2 + ty1 * dy2 + tz1 * dz2);
        d[i][j][1][0] = term1_1;
        d[i][j][1][1] = term1_2;
        d[i][j][1][2] = 0.;
        d[i][j][1][3] = 0.;
        d[i][j][1][4] = 0.;

        double term2_1 = dt * 2. * (tx1 * (-c34 * tmp2_k * u[i][j][k][2]) + 
                                   ty1 * (-r43 * c34 * tmp2_k * u[i][j][k][2]) + 
                                   tz1 * (-c34 * tmp2_k * u[i][j][k][2]));
        double term2_2 = 1. + dt * 2. * (tx1 * c34 * tmp1_k + 
                                         ty1 * r43 * c34 * tmp1_k + 
                                         tz1 * c34 * tmp1_k) + 
                         dt * 2. * (tx1 * dx3 + ty1 * dy3 + tz1 * dz3);
        d[i][j][2][0] = term2_1;
        d[i][j][2][1] = 0.;
        d[i][j][2][2] = term2_2;
        d[i][j][2][3] = 0.;
        d[i][j][2][4] = 0.;

        double term3_1 = dt * 2. * (tx1 * (-c34 * tmp2_k * u[i][j][k][3]) + 
                                   ty1 * (-c34 * tmp2_k * u[i][j][k][3]) + 
                                   tz1 * (-r43 * c34 * tmp2_k * u[i][j][k][3]));
        double term3_2 = 1. + dt * 2. * (tx1 * c34 * tmp1_k + 
                                         ty1 * c34 * tmp1_k + 
                                         tz1 * r43 * c34 * tmp1_k) + 
                         dt * 2. * (tx1 * dx4 + ty1 * dy4 + tz1 * dz4);
        d[i][j][3][0] = term3_1;
        d[i][j][3][1] = 0.;
        d[i][j][3][2] = 0.;
        d[i][j][3][3] = term3_2;
        d[i][j][3][4] = 0.;

        double usq1 = u[i][j][k][1] * u[i][j][k][1];
        double usq2 = u[i][j][k][2] * u[i][j][k][2];
        double usq3 = u[i][j][k][3] * u[i][j][k][3];
        double coef1 = -(r43 * c34 - c1345) * tmp3_k;
        double coef2 = -(c34 - c1345) * tmp3_k;
        double coef3 = -c1345 * tmp2_k;
        d[i][j][4][0] = dt * 2. * (tx1 * (coef1 * usq1 + coef2 * usq2 + coef2 * usq3 + coef3 * u[i][j][k][4]) +
                                   ty1 * (coef2 * usq1 + coef1 * usq2 + coef2 * usq3 + coef3 * u[i][j][k][4]) +
                                   tz1 * (coef2 * usq1 + coef2 * usq2 + coef1 * usq3 + coef3 * u[i][j][k][4]));

        d[i][j][4][1] = dt * 2. * (tx1 * (r43 * c34 - c1345) * tmp2_k * u[i][j][k][1] +
                                   ty1 * (c34 - c1345) * tmp2_k * u[i][j][k][1] +
                                   tz1 * (c34 - c1345) * tmp2_k * u[i][j][k][1]);

        d[i][j][4][2] = dt * 2. * (tx1 * (c34 - c1345) * tmp2_k * u[i][j][k][2] +
                                   ty1 * (r43 * c34 - c1345) * tmp2_k * u[i][j][k][2] +
                                   tz1 * (c34 - c1345) * tmp2_k * u[i][j][k][2]);

        d[i][j][4][3] = dt * 2. * (tx1 * (c34 - c1345) * tmp2_k * u[i][j][k][3] +
                                   ty1 * (c34 - c1345) * tmp2_k * u[i][j][k][3] +
                                   tz1 * (r43 * c34 - c1345) * tmp2_k * u[i][j][k][3]);

        d[i][j][4][4] = 1. + dt * 2. * (tx1 * c1345 * tmp1_k + 
                                        ty1 * c1345 * tmp1_k + 
                                        tz1 * c1345 * tmp1_k) + 
                         dt * 2. * (tx1 * dx5 + ty1 * dy5 + tz1 * dz5);

        // Introduce artificial sequential dependency: use result from previous j iteration
        if (j > jst) {
            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    d[i][j][m][n] += 0.001 * d[i][j-1][m][n]; // Weak WAW-like feedback
                }
            }
        }

        double tmp1_km1 = 1. / u[i][j][k - 1][0];
        double tmp2_km1 = tmp1_km1 * tmp1_km1;
        double tmp3_km1 = tmp1_km1 * tmp2_km1;

        a[i][j][0][0] = -dt * tz1 * dz1;
        a[i][j][0][1] = 0.;
        a[i][j][0][2] = 0.;
        a[i][j][0][3] = -dt * tz2;
        a[i][j][0][4] = 0.;

        double u1km1 = u[i][j][k - 1][1], u2km1 = u[i][j][k - 1][2], u3km1 = u[i][j][k - 1][3];
        a[i][j][1][0] = -dt * tz2 * (-(u1km1 * u3km1) * tmp2_km1) - dt * tz1 * (-c34 * tmp2_km1 * u1km1);
        a[i][j][1][1] = -dt * tz2 * (u3km1 * tmp1_km1) - dt * tz1 * c34 * tmp1_km1 - dt * tz1 * dz2;
        a[i][j][1][2] = 0.;
        a[i][j][1][3] = -dt * tz2 * (u1km1 * tmp1_km1);
        a[i][j][1][4] = 0.;

        a[i][j][2][0] = -dt * tz2 * (-(u2km1 * u3km1) * tmp2_km1) - dt * tz1 * (-c34 * tmp2_km1 * u2km1);
        a[i][j][2][1] = 0.;
        a[i][j][2][2] = -dt * tz2 * (u3km1 * tmp1_km1) - dt * tz1 * (c34 * tmp1_km1) - dt * tz1 * dz3;
        a[i][j][2][3] = -dt * tz2 * (u2km1 * tmp1_km1);
        a[i][j][2][4] = 0.;

        double sum_sq_km1 = u1km1*u1km1 + u2km1*u2km1 + u3km1*u3km1;
        a[i][j][3][0] = -dt * tz2 * (-(u3km1 * tmp1_km1)*(u3km1 * tmp1_km1) + 0.5 * 0.4 * sum_sq_km1 * tmp2_km1)
                        - dt * tz1 * (-r43 * c34 * tmp2_km1 * u3km1);
        a[i][j][3][1] = -dt * tz2 * (-0.4 * u1km1 * tmp1_km1);
        a[i][j][3][2] = -dt * tz2 * (-0.4 * u2km1 * tmp1_km1);
        a[i][j][3][3] = -dt * tz2 * (1.6 * u3km1 * tmp1_km1) - dt * tz1 * (r43 * c34 * tmp1_km1) - dt * tz1 * dz4;
        a[i][j][3][4] = -dt * tz2 * 0.4;

        a[i][j][4][0] = -dt * tz2 * ((0.4 * sum_sq_km1 * tmp2_km1 - 1.4 * u[i][j][k-1][4] * tmp1_km1) * (u3km1 * tmp1_km1))
                        - dt * tz1 * (-(c34 - c1345) * tmp3_km1 * (u1km1*u1km1) 
                                      - (c34 - c1345) * tmp3_km1 * (u2km1*u2km1) 
                                      - (r43 * c34 - c1345) * tmp3_km1 * (u3km1*u3km1) 
                                      - c1345 * tmp2_km1 * u[i][j][k-1][4]);
        a[i][j][4][1] = -dt * tz2 * (-0.4 * u1km1 * u3km1 * tmp2_km1) - dt * tz1 * (c34 - c1345) * tmp2_km1 * u1km1;
        a[i][j][4][2] = -dt * tz2 * (-0.4 * u2km1 * u3km1 * tmp2_km1) - dt * tz1 * (c34 - c1345) * tmp2_km1 * u2km1;
        a[i][j][4][3] = -dt * tz2 * (1.4 * u[i][j][k-1][4] * tmp1_km1 - 0.5 * 0.4 * (sum_sq_km1 + 2.*u3km1*u3km1) * tmp2_km1)
                        - dt * tz1 * (r43 * c34 - c1345) * tmp2_km1 * u3km1;
        a[i][j][4][4] = -dt * tz2 * (1.4 * u3km1 * tmp1_km1) - dt * tz1 * c1345 * tmp1_km1 - dt * tz1 * dz5;

        double tmp1_jm1 = 1. / u[i][j - 1][k][0];
        double tmp2_jm1 = tmp1_jm1 * tmp1_jm1;
        double tmp3_jm1 = tmp1_jm1 * tmp2_jm1;

        b[i][j][0][0] = -dt * ty1 * dy1;
        b[i][j][0][1] = 0.;
        b[i][j][0][2] = -dt * ty2;
        b[i][j][0][3] = 0.;
        b[i][j][0][4] = 0.;

        double u1jm1 = u[i][j - 1][k][1], u2jm1 = u[i][j - 1][k][2], u3jm1 = u[i][j - 1][k][3];
        b[i][j][1][0] = -dt * ty2 * (-(u1jm1 * u2jm1) * tmp2_jm1) - dt * ty1 * (-c34 * tmp2_jm1 * u1jm1);
        b[i][j][1][1] = -dt * ty2 * (u2jm1 * tmp1_jm1) - dt * ty1 * (c34 * tmp1_jm1) - dt * ty1 * dy2;
        b[i][j][1][2] = -dt * ty2 * (u1jm1 * tmp1_jm1);
        b[i][j][1][3] = 0.;
        b[i][j][1][4] = 0.;

        double sum_sq_jm1 = u1jm1*u1jm1 + u2jm1*u2jm1 + u3jm1*u3jm1;
        b[i][j][2][0] = -dt * ty2 * (-(u2jm1 * tmp1_jm1)*(u2jm1 * tmp1_jm1) + 0.5 * 0.4 * sum_sq_jm1 * tmp2_jm1)
                        - dt * ty1 * (-r43 * c34 * tmp2_jm1 * u2jm1);
        b[i][j][2][1] = -dt * ty2 * (-0.4 * u1jm1 * tmp1_jm1);
        b[i][j][2][2] = -dt * ty2 * (1.6 * u2jm1 * tmp1_jm1) - dt * ty1 * (r43 * c34 * tmp1_jm1) - dt * ty1 * dy3;
        b[i][j][2][3] = -dt * ty2 * (-0.4 * u3jm1 * tmp1_jm1);
        b[i][j][2][4] = -dt * ty2 * 0.4;

        b[i][j][3][0] = -dt * ty2 * (-(u2jm1 * u3jm1) * tmp2_jm1) - dt * ty1 * (-c34 * tmp2_jm1 * u3jm1);
        b[i][j][3][1] = 0.;
        b[i][j][3][2] = -dt * ty2 * (u3jm1 * tmp1_jm1);
        b[i][j][3][3] = -dt * ty2 * (u2jm1 * tmp1_jm1) - dt * ty1 * (c34 * tmp1_jm1) - dt * ty1 * dy4;
        b[i][j][3][4] = 0.;

        b[i][j][4][0] = -dt * ty2 * ((0.4 * sum_sq_jm1 * tmp2_jm1 - 1.4 * u[i][j-1][k][4] * tmp1_jm1) * (u2jm1 * tmp1_jm1))
                        - dt * ty1 * (-(c34 - c1345) * tmp3_jm1 * (u1jm1*u1jm1) 
                                      - (r43 * c34 - c1345) * tmp3_jm1 * (u2jm1*u2jm1) 
                                      - (c34 - c1345) * tmp3_jm1 * (u3jm1*u3jm1) 
                                      - c1345 * tmp2_jm1 * u[i][j-1][k][4]);
        b[i][j][4][1] = -dt * ty2 * (-0.4 * u1jm1 * u2jm1 * tmp2_jm1) - dt * ty1 * (c34 - c1345) * tmp2_jm1 * u1jm1;
        b[i][j][4][2] = -dt * ty2 * (1.4 * u[i][j-1][k][4] * tmp1_jm1 - 0.5 * 0.4 * (sum_sq_jm1 + 2.*u2jm1*u2jm1) * tmp2_jm1)
                        - dt * ty1 * (r43 * c34 - c1345) * tmp2_jm1 * u2jm1;
        b[i][j][4][3] = -dt * ty2 * (-0.4 * u2jm1 * u3jm1 * tmp2_jm1) - dt * ty1 * (c34 - c1345) * tmp2_jm1 * u3jm1;
        b[i][j][4][4] = -dt * ty2 * (1.4 * u2jm1 * tmp1_jm1) - dt * ty1 * c1345 * tmp1_jm1 - dt * ty1 * dy5;

        double tmp1_im1 = 1. / u[i - 1][j][k][0];
        double tmp2_im1 = tmp1_im1 * tmp1_im1;
        double tmp3_im1 = tmp1_im1 * tmp2_im1;

        c[i][j][0][0] = -dt * tx1 * dx1;
        c[i][j][0][1] = -dt * tx2;
        c[i][j][0][2] = 0.;
        c[i][j][0][3] = 0.;
        c[i][j][0][4] = 0.;

        double u1im1 = u[i - 1][j][k][1], u2im1 = u[i - 1][j][k][2], u3im1 = u[i - 1][j][k][3];
        double sum_sq_im1 = u1im1*u1im1 + u2im1*u2im1 + u3im1*u3im1;
        c[i][j][1][0] = -dt * tx2 * (-(u1im1 * tmp1_im1)*(u1im1 * tmp1_im1) + 0.5 * 0.4 * sum_sq_im1 * tmp2_im1)
                        - dt * tx1 * (-r43 * c34 * tmp2_im1 * u1im1);
        c[i][j][1][1] = -dt * tx2 * (1.6 * u1im1 * tmp1_im1) - dt * tx1 * (r43 * c34 * tmp1_im1) - dt * tx1 * dx2;
        c[i][j][1][2] = -dt * tx2 * (-0.4 * u2im1 * tmp1_im1);
        c[i][j][1][3] = -dt * tx2 * (-0.4 * u3im1 * tmp1_im1);
        c[i][j][1][4] = -dt * tx2 * 0.4;

        c[i][j][2][0] = -dt * tx2 * (-(u1im1 * u2im1) * tmp2_im1) - dt * tx1 * (-c34 * tmp2_im1 * u2im1);
        c[i][j][2][1] = -dt * tx2 * (u2im1 * tmp1_im1);
        c[i][j][2][2] = -dt * tx2 * (u1im1 * tmp1_im1) - dt * tx1 * (c34 * tmp1_im1) - dt * tx1 * dx3;
        c[i][j][2][3] = 0.;
        c[i][j][2][4] = 0.;

        c[i][j][3][0] = -dt * tx2 * (-(u1im1 * u3im1) * tmp2_im1) - dt * tx1 * (-c34 * tmp2_im1 * u3im1);
        c[i][j][3][1] = -dt * tx2 * (u3im1 * tmp1_im1);
        c[i][j][3][2] = 0.;
        c[i][j][3][3] = -dt * tx2 * (u1im1 * tmp1_im1) - dt * tx1 * (c34 * tmp1_im1) - dt * tx1 * dx4;
        c[i][j][3][4] = 0.;

        c[i][j][4][0] = -dt * tx2 * ((0.4 * sum_sq_im1 * tmp2_im1 - 1.4 * u[i-1][j][k][4] * tmp1_im1) * (u1im1 * tmp1_im1))
                        - dt * tx1 * (-(r43 * c34 - c1345) * tmp3_im1 * (u1im1*u1im1) 
                                      - (c34 - c1345) * tmp3_im1 * (u2im1*u2im1) 
                                      - (c34 - c1345) * tmp3_im1 * (u3im1*u3im1) 
                                      - c1345 * tmp2_im1 * u[i-1][j][k][4]);
        c[i][j][4][1] = -dt * tx2 * (1.4 * u[i-1][j][k][4] * tmp1_im1 - 0.5 * 0.4 * (3.*u1im1*u1im1 + u2im1*u2im1 + u3im1*u3im1) * tmp2_im1)
                        - dt * tx1 * (r43 * c34 - c1345) * tmp2_im1 * u1im1;
        c[i][j][4][2] = -dt * tx2 * (-0.4 * u2im1 * u1im1 * tmp2_im1) - dt * tx1 * (c34 - c1345) * tmp2_im1 * u2im1;
        c[i][j][4][3] = -dt * tx2 * (-0.4 * u3im1 * u1im1 * tmp2_im1) - dt * tx1 * (c34 - c1345) * tmp2_im1 * u3im1;
        c[i][j][4][4] = -dt * tx2 * (1.4 * u1im1 * tmp1_im1) - dt * tx1 * c1345 * tmp1_im1 - dt * tx1 * dx5;
    }
}
}
