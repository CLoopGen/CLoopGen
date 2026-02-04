#include <stdio.h>

extern double ten[10][2];
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (i = 0; i < 10; i++) {
    for (int j = 0; j < 2; j++) {
        ten[i][j] = (j == 0) ? 1.0 : 0.0;
        j1[i][j] = 0;
        j2[i][j] = 0;
        j3[i][j] = 0;
    }
}
}
