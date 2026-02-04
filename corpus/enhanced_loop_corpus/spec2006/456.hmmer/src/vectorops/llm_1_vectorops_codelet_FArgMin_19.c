#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) {
    int inner_i = i;
    if (inner_i < n && vec[inner_i] < vec[best])
        best = inner_i;
}
}
