#include <stdio.h>

extern double ***z;
extern int m1;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    for (i = 10 - 1; i >= m1 && i >= m1 + 5; i -= 2) { // Reduced trip count by limiting range and increasing step
        z[j3[i][1]][j2[i][1]][j1[i][1]] = 1.;
    }
}
