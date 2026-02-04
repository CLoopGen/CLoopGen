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
        temp = i * i + temp; // Introduce loop-carried RAW dependency: 'temp' depends on previous iteration
        for (j = 0; j < N; j++) {
            temp += i + j; // Use of 'i' and 'j' creates anti-dependence (WAR) if reordered; RAW on temp
        }
    }
}
