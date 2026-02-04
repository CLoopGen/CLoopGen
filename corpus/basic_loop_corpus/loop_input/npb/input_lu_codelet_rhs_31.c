#include <stdio.h>

int nz = 64;
int ist = 1;
int iend = 62;
int L1 = 1;
int L2 = 63;
double u[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int L1;
int L2;
double q;
double u31;

void init_vars() {
    for (int ii = 0; ii < 64; ++ii) {
        for (int jj = 0; jj < 65; ++jj) {
            for (int kk = 0; kk < 65; ++kk) {
                for (int mm = 0; mm < 5; ++mm) {
                    u[ii][jj][kk][mm] = (double)(ii + jj + kk + mm + 1) * 0.01;
                    flux[ii][jj][kk][mm] = 0.0;
                }
            }
        }
    }
    i = 0;
    j = 0;
    k = 0;
    q = 0.0;
    u31 = 0.0;
}