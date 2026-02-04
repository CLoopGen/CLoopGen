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
        for (j = 0; j < n; j++) {
            if (path[i][k] != INT32_MAX && path[k][j] != INT32_MAX) {
                if (path[i][k] + path[k][j] < path[i][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
}
}
