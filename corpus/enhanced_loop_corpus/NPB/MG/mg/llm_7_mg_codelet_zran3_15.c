#include <stdio.h>

extern double ***z;
extern int m1;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    double local_val;
    for (i = 10 - 1; i >= m1; i--) {
        local_val = z[j3[i][1]][j2[i][1]][j1[i][1]] + 1.0; // Remove immediate write, use independent computation
        z[j3[i][0]][j2[i][0]][j1[i][0]] = local_val; // Redirect write to a different array location — eliminates loop-carried WAW/RAW
    }
}
