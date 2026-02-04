#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
        int idx_i = i - 1;
        int idx_j = j - 1;
        path[idx_i][idx_j] = ((i * j) % 7 == 0) ? 999 : (i * j) % 7 + 1;
        if ((i + j) % 13 == 0 || (i + j) % 11 == 0)
            path[idx_i][idx_j] = 999;
    }
}
