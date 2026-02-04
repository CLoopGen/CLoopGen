#include <stdio.h>

int grid_points[3];
double bt;
double rhs[5][65][65][65];
int i;
int j;
int k;
double r1;
double r2;
double r3;
double r4;
double r5;
double t1;
double t2;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    bt = 1.5;

    for (int i_idx = 0; i_idx < 5; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int l_idx = 0; l_idx < 65; l_idx++) {
                    rhs[i_idx][j_idx][k_idx][l_idx] = (double)(i_idx + 1) * (j_idx % 10 + 1) * (k_idx % 10 + 1) * (l_idx % 10 + 1) / 100.0;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    r1 = 0.0;
    r2 = 0.0;
    r3 = 0.0;
    r4 = 0.0;
    r5 = 0.0;
    t1 = 0.0;
    t2 = 0.0;
}