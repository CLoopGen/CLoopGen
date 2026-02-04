#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                double sum = 0.0;
                for (m = 0; m < 5; m++) {
                    sum += frct[i][j][k][m];
                    frct[i][j][k][m] = sum * 0.5;
                }
            }
        }
    }
}
