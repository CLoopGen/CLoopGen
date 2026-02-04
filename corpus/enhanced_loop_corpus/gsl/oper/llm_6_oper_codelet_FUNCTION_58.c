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
    int64_t temp = 0;
    for (i = 0; i < M; i++) {
        temp = i * 2;
        for (j = 0; j < N; j++) {
            temp += j;
        }
        // WAW dependency on temp removed by using it after inner loop
        // RAW dependency: temp depends on previous value in accumulation
        // Loop-carried dependency through temp across outer loop iterations
    }
}
