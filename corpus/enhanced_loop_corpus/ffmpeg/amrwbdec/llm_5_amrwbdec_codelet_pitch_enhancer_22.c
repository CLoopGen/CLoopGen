#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *fixed_vector;
extern int i;
extern float cpe;
extern float last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 64 - 1; ++i) {
    float cur = fixed_vector[i];
    fixed_vector[i] -= cpe * (last + fixed_vector[i + 1]);
    last = cur;
    if (i % 4 == 0) {
        last *= 0.95f;
    }
}
}
