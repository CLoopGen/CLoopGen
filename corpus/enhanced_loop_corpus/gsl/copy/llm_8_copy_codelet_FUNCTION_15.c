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
    for (i = 1; i < M; i += 2) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            j++; // Increase stride to reduce effective iterations and add light computation
        }
    }
}
