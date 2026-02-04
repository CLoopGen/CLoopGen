#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j += 2) {
            if (j + 1 < n) {
                int val1 = path[i][k] + path[k][j];
                int val2 = path[i][k] + path[k][j+1];
                path[i][j]   = path[i][j]   < val1 ? path[i][j]   : val1;
                path[i][j+1] = path[i][j+1] < val2 ? path[i][j+1] : val2;
            } else {
                path[i][j] = path[i][j] < path[i][k] + path[k][j] ? path[i][j] : path[i][k] + path[k][j];
            }
        }
}
}
