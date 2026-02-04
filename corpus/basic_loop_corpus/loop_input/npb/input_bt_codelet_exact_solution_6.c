#include <stdio.h>

double ce[5][13];
double xi;
double eta;
double zeta;
double dtemp[5];
int m;

void init_vars() {
    xi = 1.5;
    eta = 2.0;
    zeta = 0.8;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            ce[i][j] = (i + 1) * (j + 1) * 0.1;
        }
        dtemp[i] = 0.0;
    }
}