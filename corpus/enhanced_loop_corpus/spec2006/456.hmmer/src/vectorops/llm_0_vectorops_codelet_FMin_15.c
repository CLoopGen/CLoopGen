#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++)
    for (i = 1; i < n; i++)
        if (vec[i] < best)
            best = vec[i];
}
