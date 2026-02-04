#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 1; i < 64; i++) {
    for (j = 1; j < 64; j++) {
        for (k = 1; k < 64; k++) {
            for (m = 0; m < 5; m++) {
                u[i][j][k][m] = u[i-1][j][k][m] + u[i][j-1][k][m] + u[i][j][k-1][m] - u[i-1][j-1][k][m];
            }
        }
    }
}
}
