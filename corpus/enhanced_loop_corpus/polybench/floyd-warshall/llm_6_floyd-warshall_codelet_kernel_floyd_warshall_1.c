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
        int temp_k = k; // Introduce local copy to modify data dependency
        for (j = 0; j < n; j++) {
            int temp_val = path[i][temp_k] + path[temp_k][j];
            if (path[i][j] > temp_val) {
                path[i][j] = temp_val;
            }
        }
    }
}
}
