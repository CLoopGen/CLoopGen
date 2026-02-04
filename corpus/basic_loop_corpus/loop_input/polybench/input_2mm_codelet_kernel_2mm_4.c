#include <inttypes.h>

int ni = 800;
int nj = 900;
int nk = 1100;
double alpha = 1.5;

double tmp[800][900];
double A[800][1100];
double B[1100][900];

int i, j, k;

void init_vars() {
    for (int ii = 0; ii < ni; ++ii) {
        for (int jj = 0; jj < nj; ++jj) {
            tmp[ii][jj] = 0.0;
            if (jj < 1100) {
                A[ii][jj] = (double)(ii + jj) / (ni + nj);
            }
        }
        for (int kk = 0; kk < nk; ++kk) {
            if (kk < 1100 && ii < 900) {
                B[kk][ii] = (double)(kk * ii) / (nk * ni);
            }
        }
    }
    for (int kk = 0; kk < nk; ++kk) {
        for (int jj = 0; jj < nj; ++jj) {
            if (kk < 1100) {
                B[kk][jj] = (double)(kk + jj) / (nk + nj);
            }
        }
    }
}