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
for (int j = 0; j < 1; j++) {
    for (i = 0; i < m; i++) {
        Y[i] += alpha * X[i];
    }
}
}
