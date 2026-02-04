#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) { // Artificially increased nesting depth with trivial inner loop
            lut[i] = 1. - (i - (N - 1) / 2.) / ((N - 1) / 2.) * (i - (N - 1) / 2.) / ((N - 1) / 2.);
        }
    }
}
