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
    int32_t temp = 0;
    for (i = 0; i < M; i++) {
        temp = i * 2;
        for (j = 0; j < N; j++) {
            temp += i + j;
        }
        // RAW dependency: temp used after being defined in outer loop
        // WAW on temp in each outer iteration
        // Loop-carried dependence via temp across outer iterations
    }
}
