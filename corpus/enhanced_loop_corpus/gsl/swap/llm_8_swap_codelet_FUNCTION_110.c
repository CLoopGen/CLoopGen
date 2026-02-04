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
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            w[i] = ATp[i] + 1;
            w[i + 1] = ATp[i + 1] - 1;
        } else {
            w[i] = ATp[i] + 1;
        }
    }
}
