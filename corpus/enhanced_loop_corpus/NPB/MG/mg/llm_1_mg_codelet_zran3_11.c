#include <stdio.h>

extern double ten[10][2];
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (int k = 0; k < 20; k++) {
    int i = k / 2;
    int j = k % 2;
    if (j == 0) {
        ten[i][j] = 1.;
        j1[i][j] = 0;
        j2[i][j] = 0;
        j3[i][j] = 0;
    } else {
        ten[i][j] = 0.;
        j1[i][j] = 0;
        j2[i][j] = 0;
        j3[i][j] = 0;
    }
}
}
