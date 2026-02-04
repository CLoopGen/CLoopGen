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
    int64_t* array = (int64_t*)calloc(M, sizeof(int64_t));
    if (!array) exit(1);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // Write access with loop-carried dependence on 'i'
        }
    }
    // Introduces a RAW (read-after-write) dependency across iterations of 'i'
    // Each iteration of outer loop writes to array[i], which could be read later (though not in this loop)
    // Inner loop has no loop-carried dependency; outer loop has WAW on array[i]
    free(array);
}
