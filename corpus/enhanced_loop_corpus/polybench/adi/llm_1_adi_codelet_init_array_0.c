#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double u[1000][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n && j < n; i++) {
        u[i][j] = (double)(i + n - j) / n;
        if (i == n - 1) {
            i = -1;
            j++;
        }
        if (j >= n) break;
    }
    j = 0;
}
