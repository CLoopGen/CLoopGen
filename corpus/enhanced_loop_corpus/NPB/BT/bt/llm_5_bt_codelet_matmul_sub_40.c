#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    for (j = 0; j < 5; j++) {
        double temp0 = ablock[0][0] * bblock[0][j] + ablock[0][1] * bblock[1][j] + ablock[0][2] * bblock[2][j] + ablock[0][3] * bblock[3][j] + ablock[0][4] * bblock[4][j];
        double temp1 = ablock[1][0] * bblock[0][j] + ablock[1][1] * bblock[1][j] + ablock[1][2] * bblock[2][j] + ablock[1][3] * bblock[3][j] + ablock[1][4] * bblock[4][j];
        double temp2 = ablock[2][0] * bblock[0][j] + ablock[2][1] * bblock[1][j] + ablock[2][2] * bblock[2][j] + ablock[2][3] * bblock[3][j] + ablock[2][4] * bblock[4][j];
        double temp3 = ablock[3][0] * bblock[0][j] + ablock[3][1] * bblock[1][j] + ablock[3][2] * bblock[2][j] + ablock[3][3] * bblock[3][j] + ablock[3][4] * bblock[4][j];
        double temp4 = ablock[4][0] * bblock[0][j] + ablock[4][1] * bblock[1][j] + ablock[4][2] * bblock[2][j] + ablock[4][3] * bblock[3][j] + ablock[4][4] * bblock[4][j];

        if (temp0 > 0.0) cblock[0][j] -= temp0;
        if (temp1 > 0.0) cblock[1][j] -= temp1;
        if (temp2 > 0.0) cblock[2][j] -= temp2;
        if (temp3 > 0.0) cblock[3][j] -= temp3;
        if (temp4 > 0.0) cblock[4][j] -= temp4;
    }
}
