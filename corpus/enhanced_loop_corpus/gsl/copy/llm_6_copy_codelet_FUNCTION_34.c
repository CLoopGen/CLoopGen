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
    size_t temp = 0;
    for (i = 0; i < M; i++) {
        temp = i * 2; // Introduce WAW dependency on temp across iterations
        for (j = i + 1; j < N; j++) {
            temp += j; // RAW dependency: use temp before updating
            temp = temp % 100; // WAW: overwrite temp, creating loop-carried dependence
        }
        // Use temp in a way that prevents optimization away
        if (temp > 1000) temp = 0;
    }
}
