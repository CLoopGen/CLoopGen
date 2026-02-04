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
double temp_d[5][5], temp_a[5][5], temp_b[5][5], temp_c[5][5];
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        tmp1 = 1. / u[i][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        temp_d[0][0] = 1. + dt * 2. * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
        temp_d[0][1] = 0.;
        temp_d[0][2] = 0.;
        temp_d[0][3] = 0.;
        temp_d[0][4] = 0.;
        temp_d[1][0] = dt * 2. * (tx1 * (-r43 * c34 * tmp2 * u[i][j][k][1]) + ty1 * (-c34 * tmp2 * u[i][j][k][1]) + tz1 * (-c34 * tmp2 * u[i][j][k][1]));
        temp_d[1][1] = 1. + dt * 2. * (tx1 * r43 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * c34 * tmp1) + dt * 2. * (tx1 * dx2 + ty1 * dy2 + tz1 * dz2);
        temp_d[1][2] = 0.;
        temp_d[1][3] = 0.;
        temp_d[1][4] = 0.;
        temp_d[2][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u[i][j][k][2]) + ty1 * (-r43 * c34 * tmp2 * u[i][j][k][2]) + tz1 * (-c34 * tmp2 * u[i][j][k][2]));
        temp_d[2][1] = 0.;
        temp_d[2][2] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * r43 * c34 * tmp1 + tz1 * c34 * tmp1) + dt * 2. * (tx1 * dx3 + ty1 * dy3 + tz1 * dz3);
        temp_d[2][3] = 0.;
        temp_d[2][4] = 0.;
        temp_d[3][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u[i][j][k][3]) + ty1 * (-c34 * tmp2 * u[i][j][k][3]) + tz1 * (-r43 * c34 * tmp2 * u[i][j][k][3]));
        temp_d[3][1] = 0.;
        temp_d[3][2] = 0.;
        temp_d[3][3] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * r43 * c34 * tmp1) + dt * 2. * (tx1 * dx4 + ty1 * dy4 + tz1 * dz4);
        temp_d[3][4] = 0.;
        temp_d[4][0] = dt * 2. * (tx1 * (-(r43 * c34 - c1345) * tmp3 * (u[i][j][k][1]*u[i][j][k][1]) - (c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]) + 
                                ty1 * (-(c34 - c1345)*tmp3*(u[i][j][k][1]*u[i][j][k][1]) - (r43*c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]) +
                                tz1 * (-(c34 - c1345)*tmp3*(u[i][j][k][1]*u[i][j][k][1]) - (c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (r43*c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]));
        temp_d[4][1] = dt * 2. * (tx1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][1] + ty1 * (c34 - c1345) * tmp2 * u[i][j][k][1] + tz1 * (c34 - c1345) * tmp2 * u[i][j][k][1]);
        temp_d[4][2] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u[i][j][k][2] + ty1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][2] + tz1 * (c34 - c1345) * tmp2 * u[i][j][k][2]);
        temp_d[4][3] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u[i][j][k][3] + ty1 * (c34 - c1345) * tmp2 * u[i][j][k][3] + tz1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][3]);
        temp_d[4][4] = 1. + dt * 2. * (tx1 * c1345 * tmp1 + ty1 * c1345 * tmp1 + tz1 * c1345 * tmp1) + dt * 2. * (tx1 * dx5 + ty1 * dy5 + tz1 * dz5);

        for (int ii = 0; ii < 5; ii++)
            for (int jj = 0; jj < 5; jj++)
                d[i][j][ii][jj] = temp_d[ii][jj];

        tmp1 = 1. / u[i + 1][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        temp_a[0][0] = -dt * tx1 * dx1;
        temp_a[0][1] = dt * tx2;
        temp_a[0][2] = 0.;
        temp_a[0][3] = 0.;
        temp_a[0][4] = 0.;
        temp_a[1][0] = dt * tx2 * (-(u[i+1][j][k][1]*tmp1)*(u[i+1][j][k][1]*tmp1) + 0.4*0.5*(u[i+1][j][k][1]*u[i+1][j][k][1] + u[i+1][j][k][2]*u[i+1][j][k][2] + u[i+1][j][k][3]*u[i+1][j][k][3])*tmp2) - dt * tx1 * (-r43 * c34 * tmp2 * u[i+1][j][k][1]);
        temp_a[1][1] = dt * tx2 * ((2.-0.4)*(u[i+1][j][k][1]*tmp1)) - dt * tx1 * (r43 * c34 * tmp1) - dt * tx1 * dx2;
        temp_a[1][2] = dt * tx2 * (-0.4 * (u[i+1][j][k][2] * tmp1));
        temp_a[1][3] = dt * tx2 * (-0.4 * (u[i+1][j][k][3] * tmp1));
        temp_a[1][4] = dt * tx2 * 0.4;
        temp_a[2][0] = dt * tx2 * (-(u[i+1][j][k][1]*u[i+1][j][k][2])*tmp2) - dt * tx1 * (-c34 * tmp2 * u[i+1][j][k][2]);
        temp_a[2][1] = dt * tx2 * (u[i+1][j][k][2] * tmp1);
        temp_a[2][2] = dt * tx2 * (u[i+1][j][k][1] * tmp1) - dt * tx1 * (c34 * tmp1) - dt * tx1 * dx3;
        temp_a[2][3] = 0.;
        temp_a[2][4] = 0.;
        temp_a[3][0] = dt * tx2 * (-(u[i+1][j][k][1]*u[i+1][j][k][3])*tmp2) - dt * tx1 * (-c34 * tmp2 * u[i+1][j][k][3]);
        temp_a[3][1] = dt * tx2 * (u[i+1][j][k][3] * tmp1);
        temp_a[3][2] = 0.;
        temp_a[3][3] = dt * tx2 * (u[i+1][j][k][1] * tmp1) - dt * tx1 * (c34 * tmp1) - dt * tx1 * dx4;
        temp_a[3][4] = 0.;
        temp_a[4][0] = dt * tx2 * ((0.4*(u[i+1][j][k][1]*u[i+1][j][k][1]+u[i+1][j][k][2]*u[i+1][j][k][2]+u[i+1][j][k][3]*u[i+1][j][k][3])*tmp2 - 1.4*(u[i+1][j][k][4]*tmp1))*(u[i+1][j][k][1]*tmp1)) - dt * tx1 * (-(r43*c34 - c1345)*tmp3*(u[i+1][j][k][1]*u[i+1][j][k][1]) - (c34-c1345)*tmp3*(u[i+1][j][k][2]*u[i+1][j][k][2]) - (c34-c1345)*tmp3*(u[i+1][j][k][3]*u[i+1][j][k][3]) - c1345*tmp2*u[i+1][j][k][4]);
        temp_a[4][1] = dt * tx2 * (1.4*(u[i+1][j][k][4]*tmp1) - 0.5*0.4*((3.*u[i+1][j][k][1]*u[i+1][j][k][1] + u[i+1][j][k][2]*u[i+1][j][k][2] + u[i+1][j][k][3]*u[i+1][j][k][3])*tmp2)) - dt * tx1 * (r43*c34 - c1345)*tmp2*u[i+1][j][k][1];
        temp_a[4][2] = dt * tx2 * (-0.4*(u[i+1][j][k][2]*u[i+1][j][k][1])*tmp2) - dt * tx1 * (c34 - c1345)*tmp2*u[i+1][j][k][2];
        temp_a[4][3] = dt * tx2 * (-0.4*(u[i+1][j][k][3]*u[i+1][j][k][1])*tmp2) - dt * tx1 * (c34 - c1345)*tmp2*u[i+1][j][k][3];
        temp_a[4][4] = dt * tx2 * (1.4*(u[i+1][j][k][1]*tmp1)) - dt * tx1 * c1345 * tmp1 - dt * tx1 * dx5;

        for (int ii = 0; ii < 5; ii++)
            for (int jj = 0; jj < 5; jj++)
                a[i][j][ii][jj] = temp_a[ii][jj];

        tmp1 = 1. / u[i][j + 1][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        temp_b[0][0] = -dt * ty1 * dy1;
        temp_b[0][1] = 0.;
        temp_b[0][2] = dt * ty2;
        temp_b[0][3] = 0.;
        temp_b[0][4] = 0.;
        temp_b[1][0] = dt * ty2 * (-(u[i][j+1][k][1]*u[i][j+1][k][2])*tmp2) - dt * ty1 * (-c34 * tmp2 * u[i][j+1][k][1]);
        temp_b[1][1] = dt * ty2 * (u[i][j+1][k][2]*tmp1) - dt * ty1 * (c34 * tmp1) - dt * ty1 * dy2;
        temp_b[1][2] = dt * ty2 * (u[i][j+1][k][1]*tmp1);
        temp_b[1][3] = 0.;
        temp_b[1][4] = 0.;
        temp_b[2][0] = dt * ty2 * (-(u[i][j+1][k][2]*tmp1)*(u[i][j+1][k][2]*tmp1) + 0.5*0.4*((u[i][j+1][k][1]*u[i][j+1][k][1] + u[i][j+1][k][2]*u[i][j+1][k][2] + u[i][j+1][k][3]*u[i][j+1][k][3])*tmp2)) - dt * ty1 * (-r43 * c34 * tmp2 * u[i][j+1][k][2]);
        temp_b[2][1] = dt * ty2 * (-0.4*(u[i][j+1][k][1]*tmp1));
        temp_b[2][2] = dt * ty2 * ((2.-0.4)*(u[i][j+1][k][2]*tmp1)) - dt * ty1 * (r43 * c34 * tmp1) - dt * ty1 * dy3;
        temp_b[2][3] = dt * ty2 * (-0.4*(u[i][j+1][k][3]*tmp1));
        temp_b[2][4] = dt * ty2 * 0.4;
        temp_b[3][0] = dt * ty2 * (-(u[i][j+1][k][2]*u[i][j+1][k][3])*tmp2) - dt * ty1 * (-c34 * tmp2 * u[i][j+1][k][3]);
        temp_b[3][1] = 0.;
        temp_b[3][2] = dt * ty2 * (u[i][j+1][k][3]*tmp1);
        temp_b[3][3] = dt * ty2 * (u[i][j+1][k][2]*tmp1) - dt * ty1 * (c34 * tmp1) - dt * ty1 * dy4;
        temp_b[3][4] = 0.;
        temp_b[4][0] = dt * ty2 * ((0.4*(u[i][j+1][k][1]*u[i][j+1][k][1]+u[i][j+1][k][2]*u[i][j+1][k][2]+u[i][j+1][k][3]*u[i][j+1][k][3])*tmp2 - 1.4*(u[i][j+1][k][4]*tmp1))*(u[i][j+1][k][2]*tmp1)) - dt * ty1 * (-(c34 - c1345)*tmp3*(u[i][j+1][k][1]*u[i][j+1][k][1]) - (r43*c34 - c1345)*tmp3*(u[i][j+1][k][2]*u[i][j+1][k][2]) - (c34 - c1345)*tmp3*(u[i][j+1][k][3]*u[i][j+1][k][3]) - c1345*tmp2*u[i][j+1][k][4]);
        temp_b[4][1] = dt * ty2 * (-0.4*(u[i][j+1][k][1]*u[i][j+1][k][2])*tmp2) - dt * ty1 * (c34 - c1345)*tmp2*u[i][j+1][k][1];
        temp_b[4][2] = dt * ty2 * (1.4*(u[i][j+1][k][4]*tmp1) - 0.5*0.4*((u[i][j+1][k][1]*u[i][j+1][k][1] + 3.*u[i][j+1][k][2]*u[i][j+1][k][2] + u[i][j+1][k][3]*u[i][j+1][k][3])*tmp2)) - dt * ty1 * (r43*c34 - c1345)*tmp2*u[i][j+1][k][2];
        temp_b[4][3] = dt * ty2 * (-0.4*(u[i][j+1][k][2]*u[i][j+1][k][3])*tmp2) - dt * ty1 * (c34 - c1345)*tmp2*u[i][j+1][k][3];
        temp_b[4][4] = dt * ty2 * (1.4*(u[i][j+1][k][2]*tmp1)) - dt * ty1 * c1345 * tmp1 - dt * ty1 * dy5;

        for (int ii = 0; ii < 5; ii++)
            for (int jj = 0; jj < 5; jj++)
                b[i][j][ii][jj] = temp_b[ii][jj];

        tmp1 = 1. / u[i][j][k + 1][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        temp_c[0][0] = -dt * tz1 * dz1;
        temp_c[0][1] = 0.;
        temp_c[0][2] = 0.;
        temp_c[0][3] = dt * tz2;
        temp_c[0][4] = 0.;
        temp_c[1][0] = dt * tz2 * (-(u[i][j][k+1][1]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (-c34 * tmp2 * u[i][j][k+1][1]);
        temp_c[1][1] = dt * tz2 * (u[i][j][k+1][3]*tmp1) - dt * tz1 * c34 * tmp1 - dt * tz1 * dz2;
        temp_c[1][2] = 0.;
        temp_c[1][3] = dt * tz2 * (u[i][j][k+1][1]*tmp1);
        temp_c[1][4] = 0.;
        temp_c[2][0] = dt * tz2 * (-(u[i][j][k+1][2]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (-c34 * tmp2 * u[i][j][k+1][2]);
        temp_c[2][1] = 0.;
        temp_c[2][2] = dt * tz2 * (u[i][j][k+1][3]*tmp1) - dt * tz1 * (c34 * tmp1) - dt * tz1 * dz3;
        temp_c[2][3] = dt * tz2 * (u[i][j][k+1][2]*tmp1);
        temp_c[2][4] = 0.;
        temp_c[3][0] = dt * tz2 * (-(u[i][j][k+1][3]*tmp1)*(u[i][j][k+1][3]*tmp1) + 0.5*0.4*((u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + u[i][j][k+1][3]*u[i][j][k+1][3])*tmp2)) - dt * tz1 * (-r43 * c34 * tmp2 * u[i][j][k+1][3]);
        temp_c[3][1] = dt * tz2 * (-0.4*(u[i][j][k+1][1]*tmp1));
        temp_c[3][2] = dt * tz2 * (-0.4*(u[i][j][k+1][2]*tmp1));
        temp_c[3][3] = dt * tz2 * ((2.-0.4)*(u[i][j][k+1][3]*tmp1)) - dt * tz1 * (r43 * c34 * tmp1) - dt * tz1 * dz4;
        temp_c[3][4] = dt * tz2 * 0.4;
        temp_c[4][0] = dt * tz2 * ((0.4*(u[i][j][k+1][1]*u[i][j][k+1][1]+u[i][j][k+1][2]*u[i][j][k+1][2]+u[i][j][k+1][3]*u[i][j][k+1][3])*tmp2 - 1.4*(u[i][j][k+1][4]*tmp1))*(u[i][j][k+1][3]*tmp1)) - dt * tz1 * (-(c34 - c1345)*tmp3*(u[i][j][k+1][1]*u[i][j][k+1][1]) - (c34 - c1345)*tmp3*(u[i][j][k+1][2]*u[i][j][k+1][2]) - (r43*c34 - c1345)*tmp3*(u[i][j][k+1][3]*u[i][j][k+1][3]) - c1345*tmp2*u[i][j][k+1][4]);
        temp_c[4][1] = dt * tz2 * (-0.4*(u[i][j][k+1][1]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (c34 - c1345)*tmp2*u[i][j][k+1][1];
        temp_c[4][2] = dt * tz2 * (-0.4*(u[i][j][k+1][2]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (c34 - c1345)*tmp2*u[i][j][k+1][2];
        temp_c[4][3] = dt * tz2 * (1.4*(u[i][j][k+1][4]*tmp1) - 0.5*0.4*((u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + 3.*u[i][j][k+1][3]*u[i][j][k+1][3])*tmp2)) - dt * tz1 * (r43*c34 - c1345)*tmp2*u[i][j][k+1][3];
        temp_c[4][4] = dt * tz2 * (1.4*(u[i][j][k+1][3]*tmp1)) - dt * tz1 * c1345 * tmp1 - dt * tz1 * dz5;

        for (int ii = 0; ii < 5; ii++)
            for (int jj = 0; jj < 5; jj++)
                c[i][j][ii][jj] = temp_c[ii][jj];
    }
}
}
