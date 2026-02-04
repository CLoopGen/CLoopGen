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
    for (i = 1; i < M; i++) {
        temp = i * i; // Introduce temporary variable with WAW dependency across iterations
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            temp += j; // RAW dependency: use of j and temp from previous statements
        }
        temp /= (i + 1); // Reduce accumulated value, creating a loop-carried dependency via temp
    }
}
