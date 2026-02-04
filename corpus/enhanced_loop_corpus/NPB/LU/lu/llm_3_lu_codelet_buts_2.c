#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double tv[64][64][5];
extern double udz[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic to Improve Locality
    for (i = iend; i >= ist; i--) {
        for (j = jend; j >= jst; j--) {
            double (* restrict u)[5] = udz[i][j]; // Base pointer for udz[i][j]
            double (* restrict vi)[65][5] = &v[i][j]; // Base for v[i][j], accessing k+1 slice
            double* restrict tvi = tv[i][j]; // Linear access for tv[i][j]

            for (m = 0; m < 5; m++) {
                tvi[m] = omega * (
                    u[m][0] * (*vi)[k + 1][0] +
                    u[m][1] * (*vi)[k + 1][1] +
                    u[m][2] * (*vi)[k + 1][2] +
                    u[m][3] * (*vi)[k + 1][3] +
                    u[m][4] * (*vi)[k + 1][4]
                );
            }
        }
    }
}
