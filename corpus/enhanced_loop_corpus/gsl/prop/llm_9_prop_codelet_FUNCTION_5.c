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
    for (i = 0; i < M / 2; i++) {
        for (j = 0; j < N / 2; j++) {
            volatile size_t acc = 0;
            acc += i * i;
            acc += j * j;
            acc = (acc >> 1) + (acc & 1);
        }
    }
}
