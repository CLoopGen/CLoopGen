#include <stdio.h>

double ce[13][5];
double xi;
double eta;
double zeta;
double dtemp[5];
int m;

void init_vars() {
    xi = 1.2;
    eta = 0.8;
    zeta = 0.5;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 5; j++) {
            ce[i][j] = (i + 1) * (j + 1) * 0.1;
        }
    }

    for (int j = 0; j < 5; j++) {
        dtemp[j] = 0.0;
    }

    m = 0;
}

void loop();