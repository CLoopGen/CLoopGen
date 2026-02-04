#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            u[i][j] = (u[i-1][j] + u[i][j-1]) / 2.0;
        }
    }
}
