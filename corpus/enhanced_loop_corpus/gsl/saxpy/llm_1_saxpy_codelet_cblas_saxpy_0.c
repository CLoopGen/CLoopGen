#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *X;
extern float *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (m > 0) {
    for (i = 0; i < m; i += 2) {
        Y[i] += alpha * X[i];
        if (i + 1 < m) {
            Y[i + 1] += alpha * X[i + 1];
        }
    }
}
}
