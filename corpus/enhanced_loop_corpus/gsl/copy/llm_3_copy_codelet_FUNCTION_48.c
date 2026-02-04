#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t stride = 2;
    for (i = 1; i < M; i += 1) {
        size_t bound = ((i) < (N) ? (i) : (N));
        for (j = 0; j < bound; j += stride) {
            if (j >= bound) break;
        }
    }
}
