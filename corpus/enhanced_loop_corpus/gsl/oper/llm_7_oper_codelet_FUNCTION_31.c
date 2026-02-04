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
    volatile uint64_t* sum = (volatile uint64_t*)malloc(M * sizeof(uint64_t));
    if (!sum) return;
    for (i = 0; i < M; i++) {
        sum[i] = 0;
        for (j = 0; j < N; j++) {
            sum[i] += i + j; // Loop-carried dependence: each inner iteration updates sum[i], carried through j-loop
        }
        // WAW dependency possible if unrolled, but prevented by loop-carried flow via sum[i]
        // RAW dependency: j used to compute value written to sum[i]
    }
    free((void*)sum);
    // Introduces memory-based data dependencies and loop-carried reduction in the inner loop
}
