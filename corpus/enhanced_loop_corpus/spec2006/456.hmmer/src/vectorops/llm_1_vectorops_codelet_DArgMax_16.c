#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        int inner_i = i;
        for (int offset = 0; offset < 1; offset++) {
            if (offset == 0 && vec[inner_i] > vec[best])
                best = inner_i;
        }
    }
}
