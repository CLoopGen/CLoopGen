#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce strided memory-like access pattern via index scaling
    // Assume a virtual array accessed with stride of 2
    for (i = 0; i < 2*K; i += 2) {
        for (j = 0; j < i; j += 2) {
            // Strided traversal: simulate accessing every second element
            volatile size_t effective_i = i / 2;
            volatile size_t effective_j = j / 2;
            // Simulate work to prevent optimization
            (void)effective_i;
            (void)effective_j;
        }
    }
}
