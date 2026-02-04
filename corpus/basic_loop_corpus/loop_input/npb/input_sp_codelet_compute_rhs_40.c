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
double u[5][65][65][65];
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double rho_i[65][65][65];
double square[65][65][65];
double rhs[5][65][65][65];
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

    for (int ii = 0; ii < 5; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    u[ii][jj][kk][ll] = (ii + 1) * 0.1 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                }
            }
        }
    }

    for (int jj = 0; jj < 65; jj++) {
        for (int kk = 0; kk < 65; kk++) {
            for (int ll = 0; ll < 65; ll++) {
                us[jj][kk][ll] = 0.1 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                vs[jj][kk][ll] = 0.2 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                ws[jj][kk][ll] = 0.3 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                qs[jj][kk][ll] = 0.4 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                rho_i[jj][kk][ll] = 1.0 + (jj % 5) * 0.1 + (kk % 5) * 0.01 + (ll % 5) * 0.001;
                square[jj][kk][ll] = 0.5 + (jj % 10) * 0.01 + (kk % 10) * 0.001 + (ll % 10) * 0.0001;
                for (int ii = 0; ii < 5; ii++) {
                    rhs[ii][jj][kk][ll] = (ii + 1) * 0.01;
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