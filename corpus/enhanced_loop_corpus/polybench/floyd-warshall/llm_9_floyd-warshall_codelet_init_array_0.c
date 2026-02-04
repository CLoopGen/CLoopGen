#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j += 2) {
        int temp1 = i % 4;
        int temp2 = j % 6;
        path[i][j] = (temp1 * temp2) % 7 + 1;
        if (i % 3 == 0 && j % 4 == 0)
            path[i][j] = 999;
        if (i + 1 < n && j + 1 < n) {
            path[i+1][j+1] = path[i][j];
        }
    }
}
}
