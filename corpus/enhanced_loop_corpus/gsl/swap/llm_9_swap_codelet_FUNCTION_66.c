#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K; i += 2) {
        for (j = i; j > 0; j--) {
            j -= (i + j) / (K + 1);
        }
    }
}
