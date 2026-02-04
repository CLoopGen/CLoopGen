#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp;
    for (i = 0; i < K; i++) {
        temp = i * i; // Introduce temporary variable with WAW dependency across iterations
        for (j = i + 1; j < K; j++) {
            temp += j; // Create RAW dependency: use of j and temp
        }
        i += temp % 2; // Introduce loop-carried dependency via update to i based on inner computation
    }
}
