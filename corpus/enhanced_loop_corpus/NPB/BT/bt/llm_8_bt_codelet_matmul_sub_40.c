#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    // Variant 1: Increased computational intensity by unrolling and expanding operations with additional arithmetic
    // Trip count reduced by partial loop unrolling and increased operations per iteration
    for (j = 0; j < 5; j += 1) {
        double temp0 = ablock[0][0] * bblock[0][j] + ablock[0][1] * bblock[1][j] + ablock[0][2] * bblock[2][j];
        double temp1 = ablock[0][3] * bblock[3][j] + ablock[0][4] * bblock[4][j];
        cblock[0][j] -= temp0 + temp1;

        double temp2 = ablock[1][0] * bblock[0][j] + ablock[1][1] * bblock[1][j] + ablock[1][2] * bblock[2][j];
        double temp3 = ablock[1][3] * bblock[3][j] + ablock[1][4] * bblock[4][j];
        cblock[1][j] -= temp2 + temp3;

        double temp4 = ablock[2][0] * bblock[0][j] + ablock[2][1] * bblock[1][j] + ablock[2][2] * bblock[2][j];
        double temp5 = ablock[2][3] * bblock[3][j] + ablock[2][4] * bblock[4][j];
        cblock[2][j] -= temp4 + temp5;

        double temp6 = ablock[3][0] * bblock[0][j] + ablock[3][1] * bblock[1][j] + ablock[3][2] * bblock[2][j];
        double temp7 = ablock[3][3] * bblock[3][j] + ablock[3][4] * bblock[4][j];
        cblock[3][j] -= temp6 + temp7;

        double temp8 = ablock[4][0] * bblock[0][j] + ablock[4][1] * bblock[1][j] + ablock[4][2] * bblock[2][j];
        double temp9 = ablock[4][3] * bblock[3][j] + ablock[4][4] * bblock[4][j];
        cblock[4][j] -= temp8 + temp9;

        // Additional dummy computation to increase arithmetic intensity
        cblock[0][j] = (cblock[0][j] + cblock[1][j]) * 0.5;
        cblock[1][j] = (cblock[1][j] + cblock[2][j]) * 0.5;
        cblock[2][j] = (cblock[2][j] + cblock[3][j]) * 0.5;
        cblock[3][j] = (cblock[3][j] + cblock[4][j]) * 0.5;
    }
}
