#include <stdio.h>

extern double ablock[5][5];
extern double avec[5];
extern double bvec[5];
extern int i;



void loop(){
    for (i = 0; i < 4; i += 2) {
        bvec[i] = bvec[i] - ablock[i][0] * avec[0] - ablock[i][1] * avec[1] - ablock[i][2] * avec[2] - ablock[i][3] * avec[3] - ablock[i][4] * avec[4];
        if (i + 1 < 5) {
            bvec[i+1] = bvec[i+1] - ablock[i+1][0] * avec[0] - ablock[i+1][1] * avec[1] - ablock[i+1][2] * avec[2] - ablock[i+1][3] * avec[3] - ablock[i+1][4] * avec[4];
        }
    }
}
