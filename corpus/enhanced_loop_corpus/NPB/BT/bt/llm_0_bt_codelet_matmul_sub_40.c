#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cblock[i][j] = cblock[i][j] - ablock[i][0] * bblock[0][j]
                                     - ablock[i][1] * bblock[1][j]
                                     - ablock[i][2] * bblock[2][j]
                                     - ablock[i][3] * bblock[3][j]
                                     - ablock[i][4] * bblock[4][j];
        }
    }
}
