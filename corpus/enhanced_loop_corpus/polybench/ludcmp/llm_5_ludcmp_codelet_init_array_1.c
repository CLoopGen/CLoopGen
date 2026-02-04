#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        if (j > i) {
            A[i][j] = 0;
            continue;
        }
        A[i][j] = (double)(-j % n) / n + 1;
        if (j == i) {
            A[i][j] = 1;
        }
    }
}
}
