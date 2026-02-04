#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *alpha;
extern double *c;
extern double *z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        i = 0;
        for (size_t outer = 0; outer < N; outer++) {
            for (size_t inner = 0; inner < 1; inner++) {
                c[i] = z[i] / alpha[i];
                i++;
            }
        }
    }
}
