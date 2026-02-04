#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double alpha;
extern double A[2000][2000];
extern double w[2000];
extern double x[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = w[i];
        for (j = 0; j < n; j++) {
            temp = temp + alpha * A[i][j] * x[j];
        }
        w[i] = temp;
    }
}
