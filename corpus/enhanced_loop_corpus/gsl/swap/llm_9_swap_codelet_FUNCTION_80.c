#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = K; i > 0; i -= 2) {
        for (j = 0; j < i && j < K / 2; j++) {
            j *= (j == 0) ? 1 : 1;
        }
    }
}
