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
        tmp1 = 1. / u[i][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        // Introduce conditional execution based on index parity to create control divergence
        if ((i + j) % 2 == 0) {
            d[i][j][0][0] = 1. + dt * 2. * (tx1 * dx1 + ty1 * dy1 + tz1 * dz1);
            d[i][j][1][1] = 1. + dt * 2. * (tx1 * r43 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * c34 * tmp1) + dt * 2. * (tx1 * dx2 + ty1 * dy2 + tz1 * dz2);
            d[i][j][2][2] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * r43 * c34 * tmp1 + tz1 * c34 * tmp1) + dt * 2. * (tx1 * dx3 + ty1 * dy3 + tz1 * dz3);
            d[i][j][3][3] = 1. + dt * 2. * (tx1 * c34 * tmp1 + ty1 * c34 * tmp1 + tz1 * r43 * c34 * tmp1) + dt * 2. * (tx1 * dx4 + ty1 * dy4 + tz1 * dz4);
            d[i][j][4][4] = 1. + dt * 2. * (tx1 * c1345 * tmp1 + ty1 * c1345 * tmp1 + tz1 * c1345 * tmp1) + dt * 2. * (tx1 * dx5 + ty1 * dy5 + tz1 * dz5);
        } else {
            // Fill diagonal with simpler expressions under alternate path
            d[i][j][0][0] = 1.0;
            d[i][j][1][1] = 1.0 + dt * tx1 * dx2;
            d[i][j][2][2] = 1.0 + dt * ty1 * dy3;
            d[i][j][3][3] = 1.0 + dt * tz1 * dz4;
            d[i][j][4][4] = 1.0 + dt * (tx1 * dx5 + ty1 * dy5 + tz1 * dz5);
        }

        // Off-diagonal elements computed unconditionally but depend on above via initialization
        d[i][j][0][1] = d[i][j][0][2] = d[i][j][0][3] = d[i][j][0][4] = 0.;
        d[i][j][1][0] = dt * 2. * (tx1 * (-r43 * c34 * tmp2 * u[i][j][k][1]) + ty1 * (-c34 * tmp2 * u[i][j][k][1]) + tz1 * (-c34 * tmp2 * u[i][j][k][1]));
        d[i][j][1][2] = d[i][j][1][3] = d[i][j][1][4] = 0.;
        d[i][j][2][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u[i][j][k][2]) + ty1 * (-r43 * c34 * tmp2 * u[i][j][k][2]) + tz1 * (-c34 * tmp2 * u[i][j][k][2]));
        d[i][j][2][1] = d[i][j][2][3] = d[i][j][2][4] = 0.;
        d[i][j][3][0] = dt * 2. * (tx1 * (-c34 * tmp2 * u[i][j][k][3]) + ty1 * (-c34 * tmp2 * u[i][j][k][3]) + tz1 * (-r43 * c34 * tmp2 * u[i][j][k][3]));
        d[i][j][3][1] = d[i][j][3][2] = d[i][j][3][4] = 0.;
        d[i][j][4][0] = dt * 2. * (tx1 * (-(r43 * c34 - c1345) * tmp3 * (u[i][j][k][1]*u[i][j][k][1]) - (c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]) +
                                ty1 * (-(c34 - c1345)*tmp3*(u[i][j][k][1]*u[i][j][k][1]) - (r43*c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]) +
                                tz1 * (-(c34 - c1345)*tmp3*(u[i][j][k][1]*u[i][j][k][1]) - (c34 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) - (r43*c34 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) - c1345*tmp2*u[i][j][k][4]));
        d[i][j][4][1] = dt * 2. * (tx1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][1] + ty1 * (c34 - c1345) * tmp2 * u[i][j][k][1] + tz1 * (c34 - c1345) * tmp2 * u[i][j][k][1]);
        d[i][j][4][2] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u[i][j][k][2] + ty1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][2] + tz1 * (c34 - c1345) * tmp2 * u[i][j][k][2]);
        d[i][j][4][3] = dt * 2. * (tx1 * (c34 - c1345) * tmp2 * u[i][j][k][3] + ty1 * (c34 - c1345) * tmp2 * u[i][j][k][3] + tz1 * (r43 * c34 - c1345) * tmp2 * u[i][j][k][3]);

        tmp1 = 1. / u[i + 1][j][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        a[i][j][0][0] = -dt * tx1 * dx1;
        a[i][j][0][1] = dt * tx2;
        a[i][j][0][2] = a[i][j][0][3] = a[i][j][0][4] = 0.;

        if (u[i+1][j][k][0] > 1e-6) {
            a[i][j][1][0] = dt * tx2 * (-(u[i+1][j][k][1]*tmp1)*(u[i+1][j][k][1]*tmp1) + 0.4 * 0.5 * (u[i+1][j][k][1]*u[i+1][j][k][1] + u[i+1][j][k][2]*u[i+1][j][k][2] + u[i+1][j][k][3]*u[i+1][j][k][3]) * tmp2)
                         - dt * tx1 * (-r43 * c34 * tmp2 * u[i+1][j][k][1]);
            a[i][j][1][1] = dt * tx2 * ((2. - 0.4) * (u[i+1][j][k][1]*tmp1)) - dt * tx1 * (r43 * c34 * tmp1) - dt * tx1 * dx2;
            a[i][j][1][2] = dt * tx2 * (-0.4 * (u[i+1][j][k][2]*tmp1));
            a[i][j][1][3] = dt * tx2 * (-0.4 * (u[i+1][j][k][3]*tmp1));
            a[i][j][1][4] = dt * tx2 * 0.4;
        } else {
            a[i][j][1][0] = a[i][j][1][1] = a[i][j][1][2] = a[i][j][1][3] = a[i][j][1][4] = 0.;
        }

        a[i][j][2][0] = dt * tx2 * (-(u[i+1][j][k][1]*u[i+1][j][k][2])*tmp2) - dt * tx1 * (-c34 * tmp2 * u[i+1][j][k][2]);
        a[i][j][2][1] = dt * tx2 * (u[i+1][j][k][2]*tmp1);
        a[i][j][2][2] = dt * tx2 * (u[i+1][j][k][1]*tmp1) - dt * tx1 * (c34 * tmp1) - dt * tx1 * dx3;
        a[i][j][2][3] = 0.; a[i][j][2][4] = 0.;

        a[i][j][3][0] = dt * tx2 * (-(u[i+1][j][k][1]*u[i+1][j][k][3])*tmp2) - dt * tx1 * (-c34 * tmp2 * u[i+1][j][k][3]);
        a[i][j][3][1] = dt * tx2 * (u[i+1][j][k][3]*tmp1);
        a[i][j][3][2] = 0.;
        a[i][j][3][3] = dt * tx2 * (u[i+1][j][k][1]*tmp1) - dt * tx1 * (c34 * tmp1) - dt * tx1 * dx4;
        a[i][j][3][4] = 0.;

        if (u[i+1][j][k][4] < 10.0) {
            a[i][j][4][0] = dt * tx2 * ((0.4 * (u[i+1][j][k][1]*u[i+1][j][k][1] + u[i+1][j][k][2]*u[i+1][j][k][2] + u[i+1][j][k][3]*u[i+1][j][k][3]) * tmp2 - 1.4 * (u[i+1][j][k][4]*tmp1)) * (u[i+1][j][k][1]*tmp1))
                         - dt * tx1 * (-(r43*c34 - c1345)*tmp3*(u[i+1][j][k][1]*u[i+1][j][k][1]) - (c34 - c1345)*tmp3*(u[i+1][j][k][2]*u[i+1][j][k][2])
                         - (c34 - c1345)*tmp3*(u[i+1][j][k][3]*u[i+1][j][k][3]) - c1345*tmp2*u[i+1][j][k][4]);
            a[i][j][4][1] = dt * tx2 * (1.4 * (u[i+1][j][k][4]*tmp1) - 0.5*0.4*((3.*u[i+1][j][k][1]*u[i+1][j][k][1] + u[i+1][j][k][2]*u[i+1][j][k][2] + u[i+1][j][k][3]*u[i+1][j][k][3])*tmp2))
                         - dt * tx1 * (r43*c34 - c1345)*tmp2*u[i+1][j][k][1];
        } else {
            a[i][j][4][0] = 0.;
            a[i][j][4][1] = dt * tx1 * c1345 * tmp2 * u[i+1][j][k][1];
        }
        a[i][j][4][2] = dt * tx2 * (-0.4 * (u[i+1][j][k][2]*u[i+1][j][k][1])*tmp2) - dt * tx1 * (c34 - c1345)*tmp2*u[i+1][j][k][2];
        a[i][j][4][3] = dt * tx2 * (-0.4 * (u[i+1][j][k][3]*u[i+1][j][k][1])*tmp2) - dt * tx1 * (c34 - c1345)*tmp2*u[i+1][j][k][3];
        a[i][j][4][4] = dt * tx2 * (1.4 * (u[i+1][j][k][1]*tmp1)) - dt * tx1 * c1345 * tmp1 - dt * tx1 * dx5;

        tmp1 = 1. / u[i][j+1][k][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        b[i][j][0][0] = -dt * ty1 * dy1;
        b[i][j][0][1] = 0.;
        b[i][j][0][2] = dt * ty2;
        b[i][j][0][3] = b[i][j][0][4] = 0.;

        b[i][j][1][0] = dt * ty2 * (-(u[i][j+1][k][1]*u[i][j+1][k][2])*tmp2) - dt * ty1 * (-c34 * tmp2 * u[i][j+1][k][1]);
        b[i][j][1][1] = dt * ty2 * (u[i][j+1][k][2]*tmp1) - dt * ty1 * (c34 * tmp1) - dt * ty1 * dy2;
        b[i][j][1][2] = dt * ty2 * (u[i][j+1][k][1]*tmp1);
        b[i][j][1][3] = b[i][j][1][4] = 0.;

        if (u[i][j+1][k][2] > 0.1) {
            b[i][j][2][0] = dt * ty2 * (-(u[i][j+1][k][2]*tmp1)*(u[i][j+1][k][2]*tmp1) + 0.5*0.4*((u[i][j+1][k][1]*u[i][j+1][k][1] + u[i][j+1][k][2]*u[i][j+1][k][2] + u[i][j+1][k][3]*u[i][j+1][k][3])*tmp2))
                         - dt * ty1 * (-r43 * c34 * tmp2 * u[i][j+1][k][2]);
            b[i][j][2][2] = dt * ty2 * ((2. - 0.4) * (u[i][j+1][k][2]*tmp1)) - dt * ty1 * (r43 * c34 * tmp1) - dt * ty1 * dy3;
        } else {
            b[i][j][2][0] = 0.;
            b[i][j][2][2] = 1.0;
        }
        b[i][j][2][1] = dt * ty2 * (-0.4 * (u[i][j+1][k][1]*tmp1));
        b[i][j][2][3] = dt * ty2 * (-0.4 * (u[i][j+1][k][3]*tmp1));
        b[i][j][2][4] = dt * ty2 * 0.4;

        b[i][j][3][0] = dt * ty2 * (-(u[i][j+1][k][2]*u[i][j+1][k][3])*tmp2) - dt * ty1 * (-c34 * tmp2 * u[i][j+1][k][3]);
        b[i][j][3][1] = 0.;
        b[i][j][3][2] = dt * ty2 * (u[i][j+1][k][3]*tmp1);
        b[i][j][3][3] = dt * ty2 * (u[i][j+1][k][2]*tmp1) - dt * ty1 * (c34 * tmp1) - dt * ty1 * dy4;
        b[i][j][3][4] = 0.;

        b[i][j][4][0] = dt * ty2 * ((0.4 * (u[i][j+1][k][1]*u[i][j+1][k][1] + u[i][j+1][k][2]*u[i][j+1][k][2] + u[i][j+1][k][3]*u[i][j+1][k][3]) * tmp2 - 1.4 * (u[i][j+1][k][4]*tmp1)) * (u[i][j+1][k][2]*tmp1))
                     - dt * ty1 * (-(c34 - c1345)*tmp3*(u[i][j+1][k][1]*u[i][j+1][k][1]) - (r43*c34 - c1345)*tmp3*(u[i][j+1][k][2]*u[i][j+1][k][2])
                     - (c34 - c1345)*tmp3*(u[i][j+1][k][3]*u[i][j+1][k][3]) - c1345*tmp2*u[i][j+1][k][4]);
        b[i][j][4][1] = dt * ty2 * (-0.4 * (u[i][j+1][k][1]*u[i][j+1][k][2])*tmp2) - dt * ty1 * (c34 - c1345)*tmp2*u[i][j+1][k][1];
        b[i][j][4][2] = dt * ty2 * (1.4 * (u[i][j+1][k][4]*tmp1) - 0.5*0.4*((u[i][j+1][k][1]*u[i][j+1][k][1] + 3.*u[i][j+1][k][2]*u[i][j+1][k][2] + u[i][j+1][k][3]*u[i][j+1][k][3])*tmp2))
                     - dt * ty1 * (r43*c34 - c1345)*tmp2*u[i][j+1][k][2];
        b[i][j][4][3] = dt * ty2 * (-0.4 * (u[i][j+1][k][2]*u[i][j+1][k][3])*tmp2) - dt * ty1 * (c34 - c1345)*tmp2*u[i][j+1][k][3];
        b[i][j][4][4] = dt * ty2 * (1.4 * (u[i][j+1][k][2]*tmp1)) - dt * ty1 * c1345 * tmp1 - dt * ty1 * dy5;

        tmp1 = 1. / u[i][j][k+1][0];
        tmp2 = tmp1 * tmp1;
        tmp3 = tmp1 * tmp2;

        c[i][j][0][0] = -dt * tz1 * dz1;
        c[i][j][0][1] = 0.;
        c[i][j][0][2] = 0.;
        c[i][j][0][3] = dt * tz2;
        c[i][j][0][4] = 0.;

        c[i][j][1][0] = dt * tz2 * (-(u[i][j][k+1][1]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (-c34 * tmp2 * u[i][j][k+1][1]);
        c[i][j][1][1] = dt * tz2 * (u[i][j][k+1][3]*tmp1) - dt * tz1 * c34 * tmp1 - dt * tz1 * dz2;
        c[i][j][1][2] = 0.;
        c[i][j][1][3] = dt * tz2 * (u[i][j][k+1][1]*tmp1);
        c[i][j][1][4] = 0.;

        c[i][j][2][0] = dt * tz2 * (-(u[i][j][k+1][2]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (-c34 * tmp2 * u[i][j][k+1][2]);
        c[i][j][2][1] = 0.;
        c[i][j][2][2] = dt * tz2 * (u[i][j][k+1][3]*tmp1) - dt * tz1 * (c34 * tmp1) - dt * tz1 * dz3;
        c[i][j][2][3] = dt * tz2 * (u[i][j][k+1][2]*tmp1);
        c[i][j][2][4] = 0.;

        if (k < 32) {
            c[i][j][3][0] = dt * tz2 * (-(u[i][j][k+1][3]*tmp1)*(u[i][j][k+1][3]*tmp1) + 0.5*0.4*((u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + u[i][j][k+1][3]*u[i][j][k+1][3])*tmp2))
                         - dt * tz1 * (-r43 * c34 * tmp2 * u[i][j][k+1][3]);
            c[i][j][3][3] = dt * tz2 * (2. - 0.4) * (u[i][j][k+1][3]*tmp1) - dt * tz1 * (r43 * c34 * tmp1) - dt * tz1 * dz4;
        } else {
            c[i][j][3][0] = -dt * tz1 * (-r43 * c34 * tmp2 * u[i][j][k+1][3]);
            c[i][j][3][3] = 1.0;
        }
        c[i][j][3][1] = dt * tz2 * (-0.4 * (u[i][j][k+1][1]*tmp1));
        c[i][j][3][2] = dt * tz2 * (-0.4 * (u[i][j][k+1][2]*tmp1));
        c[i][j][3][4] = dt * tz2 * 0.4;

        c[i][j][4][0] = dt * tz2 * ((0.4 * (u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + u[i][j][k+1][3]*u[i][j][k+1][3]) * tmp2 - 1.4 * (u[i][j][k+1][4]*tmp1)) * (u[i][j][k+1][3]*tmp1))
                     - dt * tz1 * (-(c34 - c1345)*tmp3*(u[i][j][k+1][1]*u[i][j][k+1][1]) - (c34 - c1345)*tmp3*(u[i][j][k+1][2]*u[i][j][k+1][2])
                     - (r43*c34 - c1345)*tmp3*(u[i][j][k+1][3]*u[i][j][k+1][3]) - c1345*tmp2*u[i][j][k+1][4]);
        c[i][j][4][1] = dt * tz2 * (-0.4 * (u[i][j][k+1][1]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (c34 - c1345)*tmp2*u[i][j][k+1][1];
        c[i][j][4][2] = dt * tz2 * (-0.4 * (u[i][j][k+1][2]*u[i][j][k+1][3])*tmp2) - dt * tz1 * (c34 - c1345)*tmp2*u[i][j][k+1][2];
        c[i][j][4][3] = dt * tz2 * (1.4 * (u[i][j][k+1][4]*tmp1) - 0.5*0.4*((u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + 3.*u[i][j][k+1][3]*u[i][j][k+1][3])*tmp2))
                     - dt * tz1 * (r43*c34 - c1345)*tmp2*u[i][j][k+1][3];
        c[i][j][4][4] = dt * tz2 * (1.4 * (u[i][j][k+1][3]*tmp1)) - dt * tz1 * c1345 * tmp1 - dt * tz1 * dz5;
    }
}
}
