#include <stdio.h>

int grid_points[3];
double tz2;
double zzcon2;
double zzcon3;
double zzcon4;
double zzcon5;
double dz1tz1;
double dz2tz1;
double dz3tz1;
double dz4tz1;
double dz5tz1;
double c1;
double c2;
double con43;

double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double rho_i[65][65][65];
double square[65][65][65];
double u[65][65][65][5];
double rhs[65][65][65][5];

int i;
int j;
int k;
double wijk;
double wp1;
double wm1;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    tz2 = 1.0;
    zzcon2 = 1.0;
    zzcon3 = 1.0;
    zzcon4 = 1.0;
    zzcon5 = 1.0;
    dz1tz1 = 0.1;
    dz2tz1 = 0.1;
    dz3tz1 = 0.1;
    dz4tz1 = 0.1;
    dz5tz1 = 0.1;
    c1 = 1.4;
    c2 = 0.5;
    con43 = 4.0 / 3.0;

    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 65; k++) {
                us[i][j][k] = (i + j + k) * 0.01;
                vs[i][j][k] = (i + j + k) * 0.02;
                ws[i][j][k] = (i + j + k) * 0.03;
                qs[i][j][k] = (i + j + k) * 0.04;
                rho_i[i][j][k] = (i + j + k) * 0.05;
                square[i][j][k] = (i + j + k) * 0.06;
                for (int m = 0; m < 5; m++) {
                    u[i][j][k][m] = (i + j + k + m) * 0.07;
                    rhs[i][j][k][m] = (i + j + k + m) * 0.08;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    wijk = 0.0;
    wp1 = 0.0;
    wm1 = 0.0;
}