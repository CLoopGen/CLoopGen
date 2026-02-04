#include <stdio.h>

extern double ***z;
extern int m1;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (i = 10 - 1; i >= m1; i -= 2) {
    if (i >= m1) z[j3[i][1]][j2[i][1]][j1[i][1]] = 1.;
    if (i-1 >= m1) z[j3[i-1][1]][j2[i-1][1]][j1[i-1][1]] = 1.;
}
}
