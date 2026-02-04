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
for (i = 0; i < 32; i++) {
    for (j = 0; j < 32; j++) {
        for (k = 0; k < 5; k++) {
            for (m = 0; m < 5; m++) {
                double sum = 0.0;
                for (int n = 0; n < 4; n++) {
                    sum += (a[i*2+n/2][j*2+n%2][k][m] + b[i*2+n/2][j*2+n%2][k][m]) * 0.5;
                }
                c[i][j][k][m] = sum / 4.0;
                d[i][j][k][m] = c[i][j][k][m] * c[i][j][k][m];
            }
        }
    }
}
}
