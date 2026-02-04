#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1; j++)
            vec[i] = 1. / (float)n;
}
