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
for (i = 2; i < 64 - 2; i += 2) {
    float cur1 = fixed_vector[i];
    float cur2 = fixed_vector[i + 1];
    fixed_vector[i]     -= cpe * (last + fixed_vector[i + 1]);
    fixed_vector[i + 1] -= cpe * (cur1 + fixed_vector[i + 2]);
    last = cur2;
}
}
