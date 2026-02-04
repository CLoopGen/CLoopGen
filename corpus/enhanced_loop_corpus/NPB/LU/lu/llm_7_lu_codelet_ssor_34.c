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
        double temp_a = 0.0, temp_b = 0.0, temp_c = 0.0, temp_d = 0.0;
        for (k = 0; k < 5; k++) {
            for (m = 0; m < 5; m++) {
                temp_a += a[i][j][k][m];
                temp_b += b[i][j][k][m];
                temp_c += c[i][j][k][m];
                temp_d += d[i][j][k][m];
            }
        }
        for (k = 0; k < 5; k++) {
            for (m = 0; m < 5; m++) {
                a[i][j][k][m] = temp_a / 25.0;
                b[i][j][k][m] = temp_b / 25.0;
                c[i][j][k][m] = temp_c / 25.0;
                d[i][j][k][m] = temp_d / 25.0;
            }
        }
    }
}
}
