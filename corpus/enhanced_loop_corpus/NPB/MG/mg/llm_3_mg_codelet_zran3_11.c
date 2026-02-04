#include <stdio.h>

extern double ten[10][2];
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
for (i = 0; i < 10; i++) {
    int idx = 9 - i; // Reverse access pattern: process array from end to beginning
    ten[idx][1] = 0.;
    j1[idx][1] = 0;
    j2[idx][1] = 0;
    j3[idx][1] = 0;
    ten[idx][0] = 1.;
    j1[idx][0] = 0;
    j2[idx][0] = 0;
    j3[idx][0] = 0;
}
}
