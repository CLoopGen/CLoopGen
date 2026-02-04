#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **w;
extern int m;
extern int n;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= m; i += 2) {
    for (j = 0; j <= n; j += 2) {
        w[i][j] = 0.;
        if (i + 1 <= m) w[i+1][j] = 0.;
        if (j + 1 <= n) w[i][j+1] = 0.;
        if (i + 1 <= m && j + 1 <= n) w[i+1][j+1] = 0.;
    }
}
}
