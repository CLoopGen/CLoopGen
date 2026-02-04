#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            const size_t aij = 2 * (i * tda + j);
            temp += aij; // Introduces WAW dependency on 'temp' and creates loop-carried dependency
        }
    }
    // Prevent dead code elimination by potentially using temp
    if (temp == 0) {
        temp = 1;
    }
}
