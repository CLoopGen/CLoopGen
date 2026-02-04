#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        int inner_start = i;
        for (int k = inner_start; k <= i; k++)
            if (vec[i] > vec[best])
                best = i;
    }
}
