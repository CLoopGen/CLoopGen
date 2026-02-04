#include <stdio.h>

extern double ***z;
extern int m0;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    double temp = -1.0;
    for (i = 10 - 1; i >= m0; i--) {
        temp = temp * 1.0; // Introduce artificial dependency on previous iteration via temp (WAW and loop-carried dependency)
        z[j3[i][0]][j2[i][0]][j1[i][0]] = temp;
    }
}
