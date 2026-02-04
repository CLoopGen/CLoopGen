#include <stdio.h>

double ce[5][13];
double u000ijk[5];
int m;
double xi;
double eta;
double zeta;

void init_vars() {
    xi = 0.123;
    eta = 0.456;
    zeta = 0.789;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            ce[i][j] = (i + 1) * (j + 1) * 0.01;
        }
        u000ijk[i] = 0.0;
    }
    
    m = 0;
}