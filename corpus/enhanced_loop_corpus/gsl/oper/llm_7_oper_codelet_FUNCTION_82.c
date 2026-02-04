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
    uint64_t* array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // WAW: each write to array[i] overwrites previous value from same i
                              // Loop-carried dependence on array[i]: all j-iterations write to same location
                              // WAR hazard possible if reordered: current j depends on not reading next j's write
        }
    }
    free(array);
    // Introduces loop-carried dependence across inner loop: result of array[i] depends on last j iteration
}
