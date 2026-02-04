#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K * K; i++) {
        for (j = (i % K) + 1; j < K && j < K + (i % K); j++) {
            j += (i / (K + 1)) > 0 ? 1 : 0;
        }
    }
}
