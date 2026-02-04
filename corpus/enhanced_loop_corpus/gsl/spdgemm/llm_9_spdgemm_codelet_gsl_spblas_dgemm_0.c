#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (j = 0; j < M; ++j) {
        w[j] = 0;
        for (i = 0; i < 3; ++i) {
            w[j] += i * 2;
        }
    }
}
