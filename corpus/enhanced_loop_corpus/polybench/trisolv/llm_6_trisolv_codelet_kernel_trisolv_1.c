#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double L[2000][2000];
extern double x[2000];
extern double b[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = b[i];
        for (j = 0; j < i; j++)
            temp -= L[i][j] * x[j];
        x[i] = temp / L[i][i];
    }
}
