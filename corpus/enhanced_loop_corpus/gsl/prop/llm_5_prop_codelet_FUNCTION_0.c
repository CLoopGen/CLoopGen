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
    volatile uint64_t temp;
    for (i = 0; i < M; i++) {
        temp = i * N; // Break potential WAW or WAR hazards by localizing write
        for (j = 0; j < N; j++) {
            temp ^= (temp ^ (i + j)) + 1; // Create intra-loop dependency with no loop-carried dependence
        }
        // Use temp to prevent optimization/removal
        if (temp == 0) break;
    }
}
