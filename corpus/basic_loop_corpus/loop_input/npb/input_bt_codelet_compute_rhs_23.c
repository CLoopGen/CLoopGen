#include <stdio.h>

#define GRID_POINTS_X 65
#define GRID_POINTS_Y 65
#define GRID_POINTS_Z 65

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

double us[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double vs[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double ws[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double qs[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double rho_i[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double square[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z];
double u[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z][5];
double rhs[GRID_POINTS_X][GRID_POINTS_Y][GRID_POINTS_Z][5];

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

    for (int i_idx = 0; i_idx < GRID_POINTS_X; i_idx++) {
        for (int j_idx = 0; j_idx < GRID_POINTS_Y; j_idx++) {
            for (int k_idx = 0; k_idx < GRID_POINTS_Z; k_idx++) {
                us[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.01;
                vs[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.02;
                ws[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.03;
                qs[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.04;
                rho_i[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.05;
                square[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.06;

                for (int m = 0; m < 5; m++) {
                    u[i_idx][j_idx][k_idx][m] = (i_idx + j_idx + k_idx + m) * 0.07;
                    rhs[i_idx][j_idx][k_idx][m] = (i_idx + j_idx + k_idx + m) * 0.08;
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