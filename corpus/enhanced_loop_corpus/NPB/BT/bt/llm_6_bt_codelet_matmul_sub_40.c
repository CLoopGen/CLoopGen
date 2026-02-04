#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    double temp[5];
    for (j = 0; j < 5; j++) {
        temp[j] = ablock[0][0] * bblock[0][j] + ablock[0][1] * bblock[1][j] +
                  ablock[0][2] * bblock[2][j] + ablock[0][3] * bblock[3][j] +
                  ablock[0][4] * bblock[4][j];
    }
    for (j = 0; j < 5; j++) {
        cblock[0][j] = cblock[0][j] - temp[j];
        cblock[1][j] = cblock[1][j] - (ablock[1][0] * bblock[0][j] + ablock[1][1] * bblock[1][j] +
                                      ablock[1][2] * bblock[2][j] + ablock[1][3] * bblock[3][j] +
                                      ablock[1][4] * bblock[4][j]);
        cblock[2][j] = cblock[2][j] - (ablock[2][0] * bblock[0][j] + ablock[2][1] * bblock[1][j] +
                                      ablock[2][2] * bblock[2][j] + ablock[2][3] * bblock[3][j] +
                                      ablock[2][4] * bblock[4][j]);
        cblock[3][j] = cblock[3][j] - (ablock[3][0] * bblock[0][j] + ablock[3][1] * bblock[1][j] +
                                      ablock[3][2] * bblock[2][j] + ablock[3][3] * bblock[3][j] +
                                      ablock[3][4] * bblock[4][j]);
        cblock[4][j] = cblock[4][j] - (ablock[4][0] * bblock[0][j] + ablock[4][1] * bblock[1][j] +
                                      ablock[4][2] * bblock[2][j] + ablock[4][3] * bblock[3][j] +
                                      ablock[4][4] * bblock[4][j]);
    }
}
