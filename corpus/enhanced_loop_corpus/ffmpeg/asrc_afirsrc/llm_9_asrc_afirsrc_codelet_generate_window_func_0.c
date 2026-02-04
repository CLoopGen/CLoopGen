#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N * 3; n++) {
        float x = (float)n / (float)N;
        x = x * x - 0.5f;
        if (n % 3 == 0 && n / 3 < N) {
            lut[n / 3] = x;
        }
    }
}
