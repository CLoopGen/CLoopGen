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
    // Reduced trip count and flattened nested structure by limiting inner loop execution frequency
    for (i = 0; i < M && i < N / 2; i++) {
        if ((i & 1) == 0) {  // Only even values of i trigger the inner loop
            for (j = i + 1; j < N && j < i + 10; j++) {
                // Minimal operation to reduce computational load
                volatile size_t dummy = i + j;
            }
        }
    }
}
