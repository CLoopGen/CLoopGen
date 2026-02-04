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
    for (i = 0; i < M && i < 1000; i += 2) {
        for (j = 0; j < N; j += 3) {
            volatile size_t acc = 0;
            acc += i * i;
            acc += j * j * j;
            acc = (acc + i * j) / ((i + j) + 1);
        }
    }
}
