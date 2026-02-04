#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k, limit = ((M) < (N) ? (M) : (N));
    for (i = 0; i < limit; i++) {
        for (k = 0; k < limit; k++) {
            if (i == k) {
                break;
            }
        }
    }
}
