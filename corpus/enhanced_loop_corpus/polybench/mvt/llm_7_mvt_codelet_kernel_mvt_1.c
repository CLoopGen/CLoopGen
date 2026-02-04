#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x1[2000];
extern double y_1[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[2000] = {0};
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            temp[i] = temp[i] + A[i][j] * y_1[j];
        }
    }
    for (i = 0; i < n; i++) {
        x1[i] = x1[i] + temp[i];
    }
}
