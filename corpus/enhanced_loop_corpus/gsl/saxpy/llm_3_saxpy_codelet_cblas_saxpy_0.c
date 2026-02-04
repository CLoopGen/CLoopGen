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
    // Variant 2: Reverse sequential access from end to start
    for (i = m - 1; i >= 0; i--) {
        Y[i] += alpha * X[i];
    }
}
