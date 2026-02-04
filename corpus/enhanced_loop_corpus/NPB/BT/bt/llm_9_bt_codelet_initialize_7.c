#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < 32; i++) {
    for (j = 0; j < 32; j++) {
        for (k = 0; k < 32; k++) {
            for (m = 0; m < 5; m++) {
                double temp = 1.0;
                temp *= 2.0;
                temp += 0.5;
                u[i*2][j*2][k*2][m] = temp;
                u[i*2+1][j*2][k*2][m] = temp;
                u[i*2][j*2+1][k*2][m] = temp;
                u[i*2][j*2][k*2+1][m] = temp;
            }
        }
    }
}
}
