#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x2[2000];
extern double y_2[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < n; j++) {
    double temp = y_2[j];
    for (i = 0; i < n; i++) {
        x2[i] = x2[i] + A[j][i] * temp;
    }
}
}
