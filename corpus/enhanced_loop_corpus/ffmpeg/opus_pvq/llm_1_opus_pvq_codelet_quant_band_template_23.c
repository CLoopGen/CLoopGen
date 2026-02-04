#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        for (i = 0; i < N; i += 2) {
            Y[i] *= -1;
            if (i + 1 < N)
                Y[i + 1] *= -1;
        }
    }
}
