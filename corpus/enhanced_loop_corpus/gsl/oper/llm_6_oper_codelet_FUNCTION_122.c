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
        temp = 0;
        for (j = 0; j < N; j++) {
            temp += i * j + 1;
        }
        // WAW dependency on temp eliminated per outer iteration via reinitialization
        // Introduces loop-carried dependency on temp within inner loop (RAW: j -> temp)
        printf("%" PRId64 "\n", temp);
    }
}
