#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < K; i++) {
    for (j = 0; j < i; j++) {
        K = i + j; // Introduces WAW dependency on K and makes inner loop bound dependent on outer loop via K modification
    }
}
}
