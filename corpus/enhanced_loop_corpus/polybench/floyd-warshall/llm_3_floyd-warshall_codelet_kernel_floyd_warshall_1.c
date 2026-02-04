#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < n; k += 2) {
    int k2 = k + 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Strided memory access: update two elements per iteration (j and j+1)
            if (k2 < n) {
                int sum1 = path[i][k] + path[k][j];
                int sum2 = path[i][k2] + path[k2][j];
                if (path[i][j] > sum1) path[i][j] = sum1;
                if (path[i][j] > sum2) path[i][j] = sum2;
            } else {
                int sum = path[i][k] + path[k][j];
                if (path[i][j] > sum) path[i][j] = sum;
            }
        }
    }
}
}
