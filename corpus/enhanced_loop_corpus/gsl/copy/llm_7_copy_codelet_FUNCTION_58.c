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
    int64_t sum = 0;
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            sum += i + j; // Introduce loop-carried RAW dependency on 'sum'
        }
        // Break potential WAW by resetting sum every few iterations
        if (i % 4 == 0) {
            sum = 0; // Eliminate accumulated dependency periodically
        }
    }
}
