#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = (double)(i + n) / n;
        for (j = 0; j < n; j++) {
            u[i][j] = temp - (double)j / n;
        }
    }
}
