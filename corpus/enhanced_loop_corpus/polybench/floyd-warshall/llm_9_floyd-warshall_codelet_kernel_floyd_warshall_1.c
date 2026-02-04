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
    if (k + 1 < n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                int sum1 = path[i][k] + path[k][j];
                int sum2 = path[i][k+1] + path[k+1][j];
                if (path[i][j] > sum1)
                    path[i][j] = sum1;
                // Second update does not override first; acts as additional relaxation
                if (path[i][j] > sum2)
                    path[i][j] = sum2;
            }
        }
    } else {
        // Handle leftover k when n is odd
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                path[i][j] = path[i][j] < path[i][k] + path[k][j] ? path[i][j] : path[i][k] + path[k][j];
    }
}
}
