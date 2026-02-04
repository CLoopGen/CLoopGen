#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int iglob;
extern int jglob;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
int stride = 1;
for (i = ibeg; i <= ifin; i += stride) {
    iglob = i;
    for (j = jbeg; j <= jfin; j += stride) {
        jglob = j;
        k = ki1;
        int idx_k1 = k;
        phi1[i][j] = 0.4 * (u[i][j][idx_k1][4] - 0.5 * (
            (u[i][j][idx_k1][1] * u[i][j][idx_k1][1]) +
            (u[i][j][idx_k1][2] * u[i][j][idx_k1][2]) +
            (u[i][j][idx_k1][3] * u[i][j][idx_k1][3])
        ) / u[i][j][idx_k1][0]);

        k = ki2;
        int idx_k2 = k;
        phi2[i][j] = 0.4 * (u[i][j][idx_k2][4] - 0.5 * (
            (u[i][j][idx_k2][1] * u[i][j][idx_k2][1]) +
            (u[i][j][idx_k2][2] * u[i][j][idx_k2][2]) +
            (u[i][j][idx_k2][3] * u[i][j][idx_k2][3])
        ) / u[i][j][idx_k2][0]);
    }
}
}
