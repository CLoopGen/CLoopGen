#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*x)[2];
extern int n;
extern float sum0;
extern float sum1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        for (int j = 0; j < 2 && (i + j) < n; j++) {
            sum0 += x[i + j][0] * x[i + j][0];
            sum1 += x[i + j][1] * x[i + j][1];
        }
    }
}
