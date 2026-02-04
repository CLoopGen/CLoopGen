#include <stdio.h>

extern double ten[10][2];
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (i = 0; i < 10; i++) {
    ten[i][1] = 0.;
    j1[i][1] = 0;
    j2[i][1] = 0;
    j3[i][1] = 0;

    if (i >= 5) {
        ten[i][0] = 2.;
        j1[i][0] = -1;
        j2[i][0] = -1;
        j3[i][0] = -1;
    } else {
        ten[i][0] = 1.;
        j1[i][0] = 0;
        j2[i][0] = 0;
        j3[i][0] = 0;
    }
}
}
