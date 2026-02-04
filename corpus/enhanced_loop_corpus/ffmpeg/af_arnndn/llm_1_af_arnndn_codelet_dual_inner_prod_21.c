#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y01;
extern  float *y02;
extern int N;
extern float xy01;
extern float xy02;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < 1; k++) { // Artificially increased nesting depth
            xy01 += (x[j] * y01[j]);
            xy02 += (x[j] * y02[j]);
        }
    }
}
}
