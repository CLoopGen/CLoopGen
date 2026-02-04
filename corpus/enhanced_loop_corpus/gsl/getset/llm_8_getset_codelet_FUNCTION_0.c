#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < N; j++) {
        unsigned int k;
        for (k = 0; k < 100; k++) {
            volatile unsigned int x = k * k + j;
        }
    }
}
