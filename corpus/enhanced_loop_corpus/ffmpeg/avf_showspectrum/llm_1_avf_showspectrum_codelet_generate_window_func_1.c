#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < N; outer += 8) {
    for (int inner = outer; inner < ((outer + 8) <= N ? (outer + 8) : N); inner++) {
        lut[inner] = 1.;
    }
}
}
