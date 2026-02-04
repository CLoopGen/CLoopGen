#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < M; j += 2) {
        if (j + 1 < M) {
            w[j] = ATp[j] * 2 + 1;
            w[j + 1] = ATp[j + 1] * 2 + 1;
        } else {
            w[j] = ATp[j] * 2 + 1;
        }
    }
}
