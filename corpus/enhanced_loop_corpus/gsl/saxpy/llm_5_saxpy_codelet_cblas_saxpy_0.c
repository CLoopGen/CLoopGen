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
    for (i = 0; i < m; i++) {
        if (i % 2 == 0) {
            Y[i] += alpha * X[i];
        } else {
            Y[i] += 2.0f * alpha * X[i];
        }
    }
}
