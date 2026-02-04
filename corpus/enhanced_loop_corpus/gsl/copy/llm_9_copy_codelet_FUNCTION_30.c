#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t inner_limit = ((M) < (N) ? (M) : (N)) / 2;
    size_t outer_limit = ((M) > (N) ? (M) : (N));
    for (i = 0; i < outer_limit; i++) {
        for (size_t j = 0; j < inner_limit; j++) {
            volatile size_t product = i * j + i + j;
        }
    }
}
