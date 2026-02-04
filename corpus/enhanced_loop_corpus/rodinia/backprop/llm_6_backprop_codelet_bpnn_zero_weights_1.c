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
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            w[i][j] = (i > 0) ? w[i-1][j] + 1.0 : 1.0;
        }
    }
}
