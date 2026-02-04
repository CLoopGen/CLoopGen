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
        temp = i * 2; // Introduce WAW dependency on temp, but no loop-carried dependency since it's local
        for (j = 0; j < N; j++) {
            temp += j; // RAW: temp depends on previous update; WAR avoided due to sequential execution
        }
        // Use temp to avoid optimization out
        if (temp < 0) {
            temp = 0;
        }
    }
}
