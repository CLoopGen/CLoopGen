#include <stdio.h>

int nx = 64;
int ny = 64;
int nz = 64;
int nx0 = 64;
int ny0 = 64;
double rsd[64][65][65][5];
double ce[5][13];

int i;
int j;
int k;
int m;
int iglob;
int jglob;
double xi;
double eta;
double zeta;

void init_vars() {
    for (int m = 0; m < 5; m++) {
        for (int n = 0; n < 13; n++) {
            ce[m][n] = (double)(n + 1);
        }
    }
}