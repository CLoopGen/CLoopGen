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
for (i = ist; i <= iend; i += 2) {
    for (j = jst; j <= jend; j += 2) {
        for (int ii = 0; ii < 2 && (i + ii) <= iend; ++ii) {
            for (int jj = 0; jj < 2 && (j + jj) <= jend; ++jj) {
                int ci = i + ii;
                int cj = j + jj;

                tmp1 = 1. / u[ci][cj][k][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                d[ci][cj][0][0] = 1. + dt * 2. * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
                d[ci][cj][0][1] = d[ci][cj][0][2] = d[ci][cj][0][3] = d[ci][cj][0][4] = 0.;

                double u1 = u[ci][cj][k][1], u2 = u[ci][cj][k][2], u3 = u[ci][cj][k][3], u4 = u[ci][cj][k][4];
                double sq_u1 = u1*u1, sq_u2 = u2*u2, sq_u3 = u3*u3;

                d[ci][cj][1][0] = dt * 2. * (tx1 * (-r43 * c34 * tmp2 * u1) + ty1 * (-c34 * tmp2 * u1) + tz1 * (-c34 * tmp2 * u1));
                d[ci][cj][1][1] = 1. + dt * 2. * (tx1 * r43 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * c34 * tmp1 + tx1 * dx2 + ty1 * dy2 + tz1 * dz2);
                d[ci][cj][1][2] = d[ci][cj][1][3] = d[ci][cj][1][4] = 0.;

                d[ci][cj][2][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u2) + ty1 * (-r43 * c34 * tmp2 * u2) + tz1 * (-c34 * tmp2 * u2));
                d[ci][cj][2][2] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * r43 * c34 * tmp1 + tz1 * c34 * tmp1 + tx1 * dx3 + ty1 * dy3 + tz1 * dz3);
                d[ci][cj][2][1] = d[ci][cj][2][3] = d[ci][cj][2][4] = 0.;

                d[ci][cj][3][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u3) + ty1 * (-c34 * tmp2 * u3) + tz1 * (-r43 * c34 * tmp2 * u3));
                d[ci][cj][3][3] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * r43 * c34 * tmp1 + tx1 * dx4 + ty1 * dy4 + tz1 * dz4);
                d[ci][cj][3][1] = d[ci][cj][3][2] = d[ci][cj][3][4] = 0.;

                d[ci][cj][4][0] = dt * 2. * (tx1 * (-(r43 * c34 - c1345) * tmp3 * sq_u1 - (c34 - c1345) * tmp3 * sq_u2 - (c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4) +
                                        ty1 * (-(c34 - c1345) * tmp3 * sq_u1 - (r43 * c34 - c1345) * tmp3 * sq_u2 - (c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4) +
                                        tz1 * (-(c34 - c1345) * tmp3 * sq_u1 - (c34 - c1345) * tmp3 * sq_u2 - (r43 * c34 - c1345) * tmp3 * sq_u3 - c1345 * tmp2 * u4));
                d[ci][cj][4][1] = dt * 2. * (tx1 * (r43 * c34 - c1345) * tmp2 * u1 + ty1 * (c34 - c1345) * tmp2 * u1 + tz1 * (c34 - c1345) * tmp2 * u1);
                d[ci][cj][4][2] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u2 + ty1 * (r43 * c34 - c1345) * tmp2 * u2 + tz1 * (c34 - c1345) * tmp2 * u2);
                d[ci][cj][4][3] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u3 + ty1 * (c34 - c1345) * tmp2 * u3 + tz1 * (r43 * c34 - c1345) * tmp2 * u3);
                d[ci][cj][4][4] = 1. + dt * 2. * (tx1 * c1345 * tmp1 + ty1 * c1345 * tmp1 + tz1 * c1345 * tmp1 + tx1 * dx5 + ty1 * dy5 + tz1 * dz5);

                tmp1 = 1. / u[ci + 1][cj][k][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                a[ci][cj][0][0] = -dt * tx1 * dx1;
                a[ci][cj][0][1] = dt * tx2;
                a[ci][cj][0][2] = a[ci][cj][0][3] = a[ci][cj][0][4] = 0.;

                double uu1 = u[ci + 1][cj][k][1], uu2 = u[ci + 1][cj][k][2], uu3 = u[ci + 1][cj][k][3], uu4 = u[ci + 1][cj][k][4];
                double uu1t = uu1 * tmp1, uu2t = uu2 * tmp1, uu3t = uu3 * tmp1, uu4t = uu4 * tmp1;
                double sum_sq_uu = uu1t*uu1t + uu2t*uu2t + uu3t*uu3t;

                a[ci][cj][1][0] = dt * tx2 * (-(uu1t*uu1t) + 0.4 * 0.5 * sum_sq_uu) - dt * tx1 * (-r43 * c34 * tmp2 * uu1);
                a[ci][cj][1][1] = dt * tx2 * (1.6 * uu1t) - dt * tx1 * (r43 * c34 * tmp1 + dx2);
                a[ci][cj][1][2] = dt * tx2 * (-0.4 * uu2t);
                a[ci][cj][1][3] = dt * tx2 * (-0.4 * uu3t);
                a[ci][cj][1][4] = dt * tx2 * 0.4;

                a[ci][cj][2][0] = dt * tx2 * (-uu1t * uu2t) - dt * tx1 * (-c34 * tmp2 * uu2);
                a[ci][cj][2][1] = dt * tx2 * uu2t;
                a[ci][cj][2][2] = dt * tx2 * uu1t - dt * tx1 * (c34 * tmp1 + dx3);
                a[ci][cj][2][3] = a[ci][cj][2][4] = 0.;

                a[ci][cj][3][0] = dt * tx2 * (-uu1t * uu3t) - dt * tx1 * (-c34 * tmp2 * uu3);
                a[ci][cj][3][1] = dt * tx2 * uu3t;
                a[ci][cj][3][2] = 0.;
                a[ci][cj][3][3] = dt * tx2 * uu1t - dt * tx1 * (c34 * tmp1 + dx4);
                a[ci][cj][3][4] = 0.;

                a[ci][cj][4][0] = dt * tx2 * ((0.4 * sum_sq_uu - 1.4 * uu4t) * uu1t) - dt * tx1 * (-(r43 * c34 - c1345) * tmp3 * (uu1*uu1) - 
                            (c34 - c1345) * tmp3 * (uu2*uu2) - (c34 - c1345) * tmp3 * (uu3*uu3) - c1345 * tmp2 * uu4);
                a[ci][cj][4][1] = dt * tx2 * (1.4 * uu4t - 0.5 * 0.4 * (3.*uu1t*uu1t + uu2t*uu2t + uu3t*uu3t)) - dt * tx1 * (r43 * c34 - c1345) * tmp2 * uu1;
                a[ci][cj][4][2] = dt * tx2 * (-0.4 * uu2t * uu1t) - dt * tx1 * (c34 - c1345) * tmp2 * uu2;
                a[ci][cj][4][3] = dt * tx2 * (-0.4 * uu3t * uu1t) - dt * tx1 * (c34 - c1345) * tmp2 * uu3;
                a[ci][cj][4][4] = dt * tx2 * (1.4 * uu1t) - dt * tx1 * (c1345 * tmp1 + dx5);

                tmp1 = 1. / u[ci][cj + 1][k][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                b[ci][cj][0][0] = -dt * ty1 * dy1;
                b[ci][cj][0][2] = dt * ty2;
                b[ci][cj][0][1] = b[ci][cj][0][3] = b[ci][cj][0][4] = 0.;

                double vu1 = u[ci][cj + 1][k][1], vu2 = u[ci][cj + 1][k][2], vu3 = u[ci][cj + 1][k][3], vu4 = u[ci][cj + 1][k][4];
                double vu1t = vu1 * tmp1, vu2t = vu2 * tmp1, vu3t = vu3 * tmp1, vu4t = vu4 * tmp1;
                double sum_sq_vu = vu1t*vu1t + vu2t*vu2t + vu3t*vu3t;

                b[ci][cj][1][0] = dt * ty2 * (-vu1t * vu2t) - dt * ty1 * (-c34 * tmp2 * vu1);
                b[ci][cj][1][1] = dt * ty2 * vu2t - dt * ty1 * (c34 * tmp1 + dy2);
                b[ci][cj][1][2] = dt * ty2 * vu1t;
                b[ci][cj][1][3] = b[ci][cj][1][4] = 0.;

                b[ci][cj][2][0] = dt * ty2 * (-(vu2t*vu2t) + 0.5 * 0.4 * sum_sq_vu) - dt * ty1 * (-r43 * c34 * tmp2 * vu2);
                b[ci][cj][2][1] = dt * ty2 * (-0.4 * vu1t);
                b[ci][cj][2][2] = dt * ty2 * (1.6 * vu2t) - dt * ty1 * (r43 * c34 * tmp1 + dy3);
                b[ci][cj][2][3] = dt * ty2 * (-0.4 * vu3t);
                b[ci][cj][2][4] = dt * ty2 * 0.4;

                b[ci][cj][3][0] = dt * ty2 * (-vu2t * vu3t) - dt * ty1 * (-c34 * tmp2 * vu3);
                b[ci][cj][3][2] = dt * ty2 * vu3t;
                b[ci][cj][3][3] = dt * ty2 * vu2t - dt * ty1 * (c34 * tmp1 + dy4);
                b[ci][cj][3][1] = b[ci][cj][3][4] = 0.;

                b[ci][cj][4][0] = dt * ty2 * ((0.4 * sum_sq_vu - 1.4 * vu4t) * vu2t) - dt * ty1 * (-(c34 - c1345) * tmp3 * (vu1*vu1) - 
                            (r43 * c34 - c1345) * tmp3 * (vu2*vu2) - (c34 - c1345) * tmp3 * (vu3*vu3) - c1345 * tmp2 * vu4);
                b[ci][cj][4][1] = dt * ty2 * (-0.4 * vu1t * vu2t) - dt * ty1 * (c34 - c1345) * tmp2 * vu1;
                b[ci][cj][4][2] = dt * ty2 * (1.4 * vu4t - 0.5 * 0.4 * (vu1t*vu1t + 3.*vu2t*vu2t + vu3t*vu3t)) - dt * ty1 * (r43 * c34 - c1345) * tmp2 * vu2;
                b[ci][cj][4][3] = dt * ty2 * (-0.4 * vu3t * vu2t) - dt * ty1 * (c34 - c1345) * tmp2 * vu3;
                b[ci][cj][4][4] = dt * ty2 * (1.4 * vu2t) - dt * ty1 * (c1345 * tmp1 + dy5);

                tmp1 = 1. / u[ci][cj][k + 1][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                c[ci][cj][0][0] = -dt * tz1 * dz1;
                c[ci][cj][0][3] = dt * tz2;
                c[ci][cj][0][1] = c[ci][cj][0][2] = c[ci][cj][0][4] = 0.;

                double wu1 = u[ci][cj][k + 1][1], wu2 = u[ci][cj][k + 1][2], wu3 = u[ci][cj][k + 1][3], wu4 = u[ci][cj][k + 1][4];
                double wu1t = wu1 * tmp1, wu2t = wu2 * tmp1, wu3t = wu3 * tmp1, wu4t = wu4 * tmp1;
                double sum_sq_wu = wu1t*wu1t + wu2t*wu2t + wu3t*wu3t;

                c[ci][cj][1][0] = dt * tz2 * (-wu1t * wu3t) - dt * tz1 * (-c34 * tmp2 * wu1);
                c[ci][cj][1][1] = dt * tz2 * wu3t - dt * tz1 * (c34 * tmp1 + dz2);
                c[ci][cj][1][3] = dt * tz2 * wu1t;
                c[ci][cj][1][2] = c[ci][cj][1][4] = 0.;

                c[ci][cj][2][0] = dt * tz2 * (-wu2t * wu3t) - dt * tz1 * (-c34 * tmp2 * wu2);
                c[ci][cj][2][2] = dt * tz2 * wu3t - dt * tz1 * (c34 * tmp1 + dz3);
                c[ci][cj][2][3] = dt * tz2 * wu2t;
                c[ci][cj][2][1] = c[ci][cj][2][4] = 0.;

                c[ci][cj][3][0] = dt * tz2 * (-(wu3t*wu3t) + 0.5 * 0.4 * sum_sq_wu) - dt * tz1 * (-r43 * c34 * tmp2 * wu3);
                c[ci][cj][3][1] = dt * tz2 * (-0.4 * wu1t);
                c[ci][cj][3][2] = dt * tz2 * (-0.4 * wu2t);
                c[ci][cj][3][3] = dt * tz2 * (1.6 * wu3t) - dt * tz1 * (r43 * c34 * tmp1 + dz4);
                c[ci][cj][3][4] = dt * tz2 * 0.4;

                c[ci][cj][4][0] = dt * tz2 * ((0.4 * sum_sq_wu - 1.4 * wu4t) * wu3t) - dt * tz1 * (-(c34 - c1345) * tmp3 * (wu1*wu1) - 
                            (c34 - c1345) * tmp3 * (wu2*wu2) - (r43 * c34 - c1345) * tmp3 * (wu3*wu3) - c1345 * tmp2 * wu4);
                c[ci][cj][4][1] = dt * tz2 * (-0.4 * wu1t * wu3t) - dt * tz1 * (c34 - c1345) * tmp2 * wu1;
                c[ci][cj][4][2] = dt * tz2 * (-0.4 * wu2t * wu3t) - dt * tz1 * (c34 - c1345) * tmp2 * wu2;
                c[ci][cj][4][3] = dt * tz2 * (1.4 * wu4t - 0.5 * 0.4 * (wu1t*wu1t + wu2t*wu2t + 3.*wu3t*wu3t)) - dt * tz1 * (r43 * c34 - c1345) * tmp2 * wu3;
                c[ci][cj][4][4] = dt * tz2 * (1.4 * wu3t) - dt * tz1 * (c1345 * tmp1 + dz5);
            }
        }
    }
}
}
