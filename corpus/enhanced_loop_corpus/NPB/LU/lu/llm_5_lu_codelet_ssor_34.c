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
        int skip_c_d = (i % 4 == 0);
        for (k = 0; k < 5; k++) {
            for (m = 0; m < 5; m++) {
                a[i][j][k][m] = 0.;
                b[i][j][k][m] = 0.;
                if (!skip_c_d) {
                    c[i][j][k][m] = 0.;
                    d[i][j][k][m] = 0.;
                }
            }
        }
    }
}
}
