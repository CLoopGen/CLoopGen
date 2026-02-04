#include <stdio.h>

extern double ten[10][2];
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (i = 0; i < 20; i += 2) {  // Increased trip count with step adjustment
    int idx1 = i;
    int idx2 = i + 1;
    if (idx1 < 10) {
        ten[idx1][0] = 1.;
        ten[idx1][1] = 0.;
        j1[idx1][0] = 0;
        j1[idx1][1] = 0;
        j2[idx1][0] = 0;
        j2[idx1][1] = 0;
        j3[idx1][0] = 0;
        j3[idx1][1] = 0;
    }
    if (idx2 < 10) {
        ten[idx2][0] = 1.;
        ten[idx2][1] = 0.;
        j1[idx2][0] = 0;
        j1[idx2][1] = 0;
        j2[idx2][0] = 0;
        j2[idx2][1] = 0;
        j3[idx2][0] = 0;
        j3[idx2][1] = 0;
    }
    // Simulates higher computational intensity via duplicated logic and expanded iteration space
}
}
