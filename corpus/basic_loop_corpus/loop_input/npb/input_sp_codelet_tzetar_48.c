#include <stdio.h>

int grid_points[3];
double bt;
double c2iv;
double u[5][65][65][65];
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double ainv[65][65][65];
double speed[65][65][65];
double rhs[5][65][65][65];
int i;
int j;
int k;
double t1;
double t2;
double t3;
double ac;
double xvel;
double yvel;
double zvel;
double r1;
double r2;
double r3;
double r4;
double r5;
double btuz;
double acinv;
double ac2u;
double uzik1;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    bt = 1.5;
    c2iv = 0.8;

    for (int i_idx = 0; i_idx < 5; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int l_idx = 0; l_idx < 65; l_idx++) {
                    u[i_idx][j_idx][k_idx][l_idx] = (i_idx + 1) * 0.1 + (j_idx % 7) * 0.01 + (k_idx % 5) * 0.001 + (l_idx % 3) * 0.0001;
                    rhs[i_idx][j_idx][k_idx][l_idx] = (i_idx + 1) * 0.2 + (j_idx % 6) * 0.02 + (k_idx % 4) * 0.002 + (l_idx % 2) * 0.0002;
                }
            }
        }
    }

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                us[i_idx][j_idx][k_idx] = (i_idx % 3) * 0.1 + (j_idx % 4) * 0.01 + (k_idx % 5) * 0.001;
                vs[i_idx][j_idx][k_idx] = (i_idx % 4) * 0.1 + (j_idx % 5) * 0.01 + (k_idx % 6) * 0.001;
                ws[i_idx][j_idx][k_idx] = (i_idx % 5) * 0.1 + (j_idx % 6) * 0.01 + (k_idx % 7) * 0.001;
                qs[i_idx][j_idx][k_idx] = (i_idx % 2) * 0.2 + (j_idx % 3) * 0.02 + (k_idx % 4) * 0.002;
                ainv[i_idx][j_idx][k_idx] = 1.0 / (1.0 + (i_idx % 10) * 0.1 + (j_idx % 10) * 0.01 + (k_idx % 10) * 0.001);
                speed[i_idx][j_idx][k_idx] = 1.0 + (i_idx % 5) * 0.05 + (j_idx % 5) * 0.005 + (k_idx % 5) * 0.0005;
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
    xvel = 0.0;
    yvel = 0.0;
    zvel = 0.0;
    r1 = 0.0;
    r2 = 0.0;
    r3 = 0.0;
    r4 = 0.0;
    r5 = 0.0;
    btuz = 0.0;
    acinv = 0.0;
    ac2u = 0.0;
    uzik1 = 0.0;
}