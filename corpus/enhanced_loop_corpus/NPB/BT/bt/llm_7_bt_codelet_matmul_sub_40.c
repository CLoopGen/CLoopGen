#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    for (j = 0; j < 5; j++) {
        double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0, sum4 = 0.0, sum5 = 0.0;
        for (int k = 0; k < 5; k++) {
            sum1 += ablock[0][k] * bblock[k][j];
            sum2 += ablock[1][k] * bblock[k][j];
            sum3 += ablock[2][k] * bblock[k][j];
            sum4 += ablock[3][k] * bblock[k][j];
            sum5 += ablock[4][k] * bblock[k][j];
        }
        cblock[0][j] -= sum1;
        cblock[1][j] -= sum2;
        cblock[2][j] -= sum3;
        cblock[3][j] -= sum4;
        cblock[4][j] -= sum5;
    }
}
