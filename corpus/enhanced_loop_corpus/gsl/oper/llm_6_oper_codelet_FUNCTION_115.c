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
        temp = i; // Introduce WAW dependency on 'temp' across iterations
        for (j = 0; j < N; j++) {
            temp += i + j; // RAW dependency: 'i', 'j' read before update to 'temp'
        }
        // Loop-carried dependency via 'temp' from one outer iteration to next
        temp *= 2;
    }
}
