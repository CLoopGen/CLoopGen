#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double lhs[65][65][65][3][5][5];

int i;
int j;
int k;
int m;
int n;

void init_vars() {
    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int p = 0; p < 3; p++) {
                    for (int mm = 0; mm < 5; mm++) {
                        for (int nn = 0; nn < 5; nn++) {
                            lhs[ii][jj][kk][p][mm][nn] = (double)(ii + jj + kk + p + mm + nn);
                        }
                    }
                }
            }
        }
    }
}