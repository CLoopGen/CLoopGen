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
    for (j = 0; j < n; j++) {
        int pkj = path[k][j]; // Break WAW and WAR dependencies by caching
        for (i = 0; i < n; i++) {
            int pik = path[i][k];
            int sum = pik + pkj;
            // Eliminate loop-carried dependence on path[i][j] update
            if (path[i][j] > sum) {
                path[i][j] = sum;
            }
        }
    }
}
}
