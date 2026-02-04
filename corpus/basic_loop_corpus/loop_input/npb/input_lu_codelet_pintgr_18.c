#include <stdio.h>

int ki1 = 1;
int ki2 = 4;
double u[64][65][65][5];
int i;
int j;
int k;
int ibeg = 1;
int ifin = 62;
int jbeg = 1;
int jfin = 62;
int iglob;
int jglob;
double phi1[66][66];
double phi2[66][66];

void init_vars() {
    for (int idx0 = 0; idx0 < 64; idx0++) {
        for (int idx1 = 0; idx1 < 65; idx1++) {
            for (int idx2 = 0; idx2 < 65; idx2++) {
                for (int idx3 = 0; idx3 < 5; idx3++) {
                    u[idx0][idx1][idx2][idx3] = (double)(idx0 + idx1 + idx2 + idx3 + 1) * 0.01;
                }
            }
        }
    }
    
    for (int idx0 = 0; idx0 < 66; idx0++) {
        for (int idx1 = 0; idx1 < 66; idx1++) {
            phi1[idx0][idx1] = 0.0;
            phi2[idx0][idx1] = 0.0;
        }
    }
    
    ki1 = 1;
    ki2 = 4;
    ibeg = 1;
    ifin = 62;
    jbeg = 1;
    jfin = 62;
}