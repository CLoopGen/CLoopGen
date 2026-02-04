#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= K; i <<= 1) {
    for (j = 0; j < i; j++) {
        volatile size_t dummy = j * j + i;
    }
}
}
