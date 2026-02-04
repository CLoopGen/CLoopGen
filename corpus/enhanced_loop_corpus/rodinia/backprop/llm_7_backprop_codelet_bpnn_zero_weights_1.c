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
    float temp;
    for (i = 0; i <= m; i++) {
        temp = 0.0;
        for (j = 0; j <= n; j++) {
            temp += 1.0;
            w[i][j] = temp;
        }
    }
}
