#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K; i++) {
        // Add early exit based on a control condition
        if (i * i >= K) {
            break;
        }
    }
}
