#include <stdio.h>

extern  double a[64][64][5][5];
extern  double b[64][64][5][5];
extern  double c[64][64][5][5];
extern  double d[64][64][5][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
        for (k = 0; k < 5; k++) {
            a[i][j][k][0] = 0.;
            b[i][j][k][0] = 0.;
            c[i][j][k][0] = 0.;
            d[i][j][k][0] = 0.;
            a[i][j][k][1] = 0.;
            b[i][j][k][1] = 0.;
            c[i][j][k][1] = 0.;
            d[i][j][k][1] = 0.;
            a[i][j][k][2] = 0.;
            b[i][j][k][2] = 0.;
            c[i][j][k][2] = 0.;
            d[i][j][k][2] = 0.;
            a[i][j][k][3] = 0.;
            b[i][j][k][3] = 0.;
            c[i][j][k][3] = 0.;
            d[i][j][k][3] = 0.;
            a[i][j][k][4] = 0.;
            b[i][j][k][4] = 0.;
            c[i][j][k][4] = 0.;
            d[i][j][k][4] = 0.;
        }
    }
}
}
