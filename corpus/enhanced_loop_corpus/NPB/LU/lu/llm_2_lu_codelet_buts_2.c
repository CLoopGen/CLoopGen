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
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Loop Order (interchange j and m loops)
    for (i = iend; i >= ist; i--) {
        for (m = 0; m < 5; m++) {
            for (j = jend; j >= jst; j--) {
                tv[i][j][m] = omega * (
                    udz[i][j][m][0] * v[i][j][k + 1][0] +
                    udz[i][j][m][1] * v[i][j][k + 1][1] +
                    udz[i][j][m][2] * v[i][j][k + 1][2] +
                    udz[i][j][m][3] * v[i][j][k + 1][3] +
                    udz[i][j][m][4] * v[i][j][k + 1][4]
                );
            }
        }
    }
}
