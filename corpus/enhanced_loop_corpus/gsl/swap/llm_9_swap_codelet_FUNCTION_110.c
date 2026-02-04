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
    size_t j;
    for (i = 0; i < N; ++i) {
        w[i] = ATp[i];
        for (j = 0; j < 3 && (i + j) < N; ++j) {
            w[i] += ATp[i + j] * 2;
        }
    }
}
