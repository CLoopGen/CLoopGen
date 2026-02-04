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
    for (i = 0; i < M / 2; i += 2) {
        for (j = 0; j < N / 2; j += 2) {
            volatile size_t x = i + j;
            volatile size_t y = i * i + j * j;
            volatile size_t z = (x > y) ? x : y;
        }
    }
}
