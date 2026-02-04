#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 1; i < n; i++)
            if (vec[i] < vec[best])
                best = i;
}
