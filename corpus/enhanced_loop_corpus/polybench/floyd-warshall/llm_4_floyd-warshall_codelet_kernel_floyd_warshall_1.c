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
    for (i = 0; i < n; i++) {
        if (i == k) continue;
        for (j = 0; j < n; j++) {
            if (j == k || i == j) continue;
            int intermediate = path[i][k] + path[k][j];
            if (intermediate < path[i][j]) {
                path[i][j] = intermediate;
            }
        }
    }
}
}
