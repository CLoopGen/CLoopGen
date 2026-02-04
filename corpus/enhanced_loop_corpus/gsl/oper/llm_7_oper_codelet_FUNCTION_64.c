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
    for (i = 0; i < M && i < 100; i += 2) {
        for (j = N; j > 0; j--) {
            volatile size_t acc = 0;
            acc += i + j;
            acc *= acc;
        }
    }
}
