#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda_a;
extern  size_t tda_b;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t accumulator = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Remove direct independent indexing and create WAW and WAR dependencies via shared accumulator
            const size_t raw_index_a = i * tda_a + j;
            const size_t raw_index_b = i * tda_b + j;
            // Write-after-write: multiple writes to accumulator in same location
            accumulator = raw_index_a;
            accumulator = raw_index_b;  // Overwrite creates WAW
            // Use accumulator immediately — creates WAR if reordered
            const size_t combined = accumulator * 2;
            (void)combined;
        }
    }
    // Ensure accumulator is used to prevent dead code elimination
    if (accumulator == 0) {
        accumulator = 1;
    }
}
