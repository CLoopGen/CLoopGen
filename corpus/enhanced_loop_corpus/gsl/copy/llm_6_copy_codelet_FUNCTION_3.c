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
        temp = i * 2; // Introduce WAW dependency on 'temp' across iterations
        for (j = i + 1; j < N; j++) {
            temp += j - i; // RAW dependency: 'temp' depends on previous update, loop-carried via 'temp'
        }
    }
}
