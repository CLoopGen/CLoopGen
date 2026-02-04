#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (M > 0 && N > 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++) {
            for (; i < ((M) < (N) ? (M) : (N)); i++) {
            }
        }
    }
}
