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
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        tv[i][j][0] = omega * (udz[i][j][0][0] * v[i][j][k + 1][0] + udz[i][j][0][1] * v[i][j][k + 1][1] + udz[i][j][0][2] * v[i][j][k + 1][2] + udz[i][j][0][3] * v[i][j][k + 1][3] + udz[i][j][0][4] * v[i][j][k + 1][4]);
        tv[i][j][1] = omega * (udz[i][j][1][0] * v[i][j][k + 1][0] + udz[i][j][1][1] * v[i][j][k + 1][1] + udz[i][j][1][2] * v[i][j][k + 1][2] + udz[i][j][1][3] * v[i][j][k + 1][3] + udz[i][j][1][4] * v[i][j][k + 1][4]);
        tv[i][j][2] = omega * (udz[i][j][2][0] * v[i][j][k + 1][0] + udz[i][j][2][1] * v[i][j][k + 1][1] + udz[i][j][2][2] * v[i][j][k + 1][2] + udz[i][j][2][3] * v[i][j][k + 1][3] + udz[i][j][2][4] * v[i][j][k + 1][4]);
        tv[i][j][3] = omega * (udz[i][j][3][0] * v[i][j][k + 1][0] + udz[i][j][3][1] * v[i][j][k + 1][1] + udz[i][j][3][2] * v[i][j][k + 1][2] + udz[i][j][3][3] * v[i][j][k + 1][3] + udz[i][j][3][4] * v[i][j][k + 1][4]);
        tv[i][j][4] = omega * (udz[i][j][4][0] * v[i][j][k + 1][0] + udz[i][j][4][1] * v[i][j][k + 1][1] + udz[i][j][4][2] * v[i][j][k + 1][2] + udz[i][j][4][3] * v[i][j][k + 1][3] + udz[i][j][4][4] * v[i][j][k + 1][4]);
    }
}
}
