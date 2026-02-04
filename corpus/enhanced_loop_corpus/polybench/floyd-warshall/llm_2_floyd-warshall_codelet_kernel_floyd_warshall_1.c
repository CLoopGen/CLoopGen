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
        int* path_ik = path[i];
        int* path_kk = path[k];
        for (j = 0; j < n; j++) {
            int temp = path_ik[k] + path_kk[j];
            path[i][j] = path[i][j] < temp ? path[i][j] : temp;
        }
    }
}
}
