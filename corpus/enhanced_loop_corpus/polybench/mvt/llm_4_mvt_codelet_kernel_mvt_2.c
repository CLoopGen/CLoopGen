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
for (i = 0; i < n; i++) {
    double temp = 0.0;
    for (j = 0; j < n; j++) {
        if (A[j][i] != 0.0) {
            temp += A[j][i] * y_2[j];
        }
    }
    x2[i] = x2[i] + temp;
}
}
