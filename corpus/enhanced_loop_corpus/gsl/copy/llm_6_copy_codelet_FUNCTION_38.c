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
    int64_t temp = 0;
    for (i = 1; i < M; i++) {
        temp = i * i; // Introduce WAW dependency on temp, but no loop-carried dependency since temp is reused
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            temp += i + j; // RAW: j and i used before update to temp
        }
        // temp value overwritten in next outer iteration — weak WAW across iterations
    }
}
