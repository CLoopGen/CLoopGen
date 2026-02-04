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
    size_t temp = 0;
    for (i = 1; i < M; i++) {
        temp = i * i; // Introduce local dependency: each iteration computes temp based on i
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            temp += j; // RAW dependency: use of j and temp, no loop-carried dependency across outer loop
        }
        // Write back or use temp to maintain semantic relevance
        if (temp > 1000) {
            temp = 0;
        }
    }
}
