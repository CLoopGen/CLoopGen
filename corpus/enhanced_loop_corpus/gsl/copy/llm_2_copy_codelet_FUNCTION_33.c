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
for (i = 1; i < M; i++) {
    for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
        // Change memory access to strided pattern by accessing every second element conceptually
        // Introduce a dummy array access with stride of 2 using index calculated from j
        volatile char dummy[1024];
        size_t idx = (j * 2) % 1024; // Strided access: step of 2 with wrap-around
        dummy[idx] += 1;
    }
}
}
