#include <stdio.h>

double u[65][65][65][5];
int i;
int j;
int k;
int m;

void init_vars() {
    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int mm = 0; mm < 5; mm++) {
                    u[ii][jj][kk][mm] = 0.0;
                }
            }
        }
    }
    i = 0;
    j = 0;
    k = 0;
    m = 0;
}