#include <stdio.h>

int grid_points[3];
double ty2;
double yycon2;
double yycon3;
double yycon4;
double yycon5;
double dy1ty1;
double dy2ty1;
double dy3ty1;
double dy4ty1;
double dy5ty1;
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
double vijk;
double vp1;
double vm1;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    ty2 = 1.0;
    yycon2 = 1.0;
    yycon3 = 1.0;
    yycon4 = 1.0;
    yycon5 = 1.0;
    dy1ty1 = 0.1;
    dy2ty1 = 0.1;
    dy3ty1 = 0.1;
    dy4ty1 = 0.1;
    dy5ty1 = 0.1;
    c1 = 1.4;
    c2 = 0.5;
    con43 = 4.0 / 3.0;

    for (int i_idx = 0; i_idx < 5; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int l_idx = 0; l_idx < 65; l_idx++) {
                    u[i_idx][j_idx][k_idx][l_idx] = (i_idx + 1) * 0.1 * (j_idx % 7 + k_idx % 5 + l_idx % 3);
                }
            }
        }
    }

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                us[i_idx][j_idx][k_idx] = (i_idx % 3 + j_idx % 4 + k_idx % 5) * 0.01;
                vs[i_idx][j_idx][k_idx] = (i_idx % 5 + j_idx % 3 + k_idx % 7) * 0.01;
                ws[i_idx][j_idx][k_idx] = (i_idx % 4 + j_idx % 6 + k_idx % 3) * 0.01;
                qs[i_idx][j_idx][k_idx] = (i_idx % 3 + j_idx % 5 + k_idx % 4) * 0.01;
                rho_i[i_idx][j_idx][k_idx] = (i_idx % 7 + j_idx % 3 + k_idx % 5) * 0.01;
                square[i_idx][j_idx][k_idx] = (i_idx % 2 + j_idx % 3 + k_idx % 2) * 0.02;
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (m_idx + 1) * 0.001 * (i_idx % 4 + j_idx % 3 + k_idx % 5);
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    vijk = 0.0;
    vp1 = 0.0;
    vm1 = 0.0;
}