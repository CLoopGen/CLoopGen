#include <stdio.h>

extern double ***z;
extern int m0;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    for (i = 10 - 1; i >= m0; i--) {
        if (j3[i][0] >= 0 && j2[i][0] >= 0 && j1[i][0] >= 0) {
            z[j3[i][0]][j2[i][0]][j1[i][0]] = -1.;
        }
    }
}
