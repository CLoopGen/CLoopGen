#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = (double)i / n;
        for (j = 0; j < n; j++) {
            A[i][j] = temp * (j + 2) + 2.0 / n;
        }
    }
}
