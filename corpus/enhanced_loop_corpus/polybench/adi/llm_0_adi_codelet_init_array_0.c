#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        u[i][0] = (double)(i + n - 0) / n;
        for (j = 1; j < n; j++) {
            u[i][j] = (double)(i + n - j) / n;
        }
    }
}
