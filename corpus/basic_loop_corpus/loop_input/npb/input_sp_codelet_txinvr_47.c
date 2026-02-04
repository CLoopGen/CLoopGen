#include <stdio.h>

int grid_points[3];
double c2;
double bt;
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double ainv[65][65][65];
double rho_i[65][65][65];
double speed[65][65][65];
double rhs[5][65][65][65];
int i;
int j;
int k;
double t1;
double t2;
double t3;
double ac;
double ru1;
double uu;
double vv;
double ww;
double r1;
double r2;
double r3;
double r4;
double r5;
double ac2inv;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    c2 = 1.5;
    bt = 0.8;

    for (int ii = 0; ii < 65; ++ii) {
        for (int jj = 0; jj < 65; ++jj) {
            for (int kk = 0; kk < 65; ++kk) {
                us[ii][jj][kk] = 1.0 + ii * 0.001;
                vs[ii][jj][kk] = 1.0 + jj * 0.001;
                ws[ii][jj][kk] = 1.0 + kk * 0.001;
                qs[ii][jj][kk] = 1.0 + (ii + jj + kk) * 0.0001;
                ainv[ii][jj][kk] = 1.0 / (2.0 + ii * 0.001);
                rho_i[ii][jj][kk] = 1.2 + (ii * jj) * 0.00001;
                speed[ii][jj][kk] = 300.0 + (ii - jj) * 0.1;
                for (int ll = 0; ll < 5; ++ll) {
                    rhs[ll][ii][jj][kk] = (ll + 1) * 0.1 + ii * 0.001 - jj * 0.002 + kk * 0.003;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    t1 = 0.0;
    t2 = 0.0;
    t3 = 0.0;
    ac = 0.0;
    ru1 = 0.0;
    uu = 0.0;
    vv = 0.0;
    ww = 0.0;
    r1 = 0.0;
    r2 = 0.0;
    r3 = 0.0;
    r4 = 0.0;
    r5 = 0.0;
    ac2inv = 0.0;
}