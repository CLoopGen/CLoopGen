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
    uint64_t temp = 0;
    for (i = 0; i < M; i++) {
        temp = 0;
        for (j = 0; j < N; j++) {
            temp += i * j + 1;
        }
        temp /= (N > 0) ? N : 1;
        temp += i;
    }
}
