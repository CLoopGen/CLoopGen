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
            for (m = 0; m < 5; m++) {
                // Access with consecutive memory layout in m-dimension, unroll manually for better spatial locality
                int base_a = ((i * 64 + j) * 5 + k) * 5;
                int base_b = base_a;
                int base_c = base_a;
                int base_d = base_a;
                a[i][j][k][m] = 0.;
                b[i][j][k][m] = 0.;
                c[i][j][k][m] = 0.;
                d[i][j][k][m] = 0.;
            }
        }
    }
}
}
