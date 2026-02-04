#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern int *w;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        size_t i = 0;
        for (; i < N - 1; ++i) {
            w[i] = ATp[i];
        }
        w[i] = ATp[i]; // Handle last element separately
    }
}
