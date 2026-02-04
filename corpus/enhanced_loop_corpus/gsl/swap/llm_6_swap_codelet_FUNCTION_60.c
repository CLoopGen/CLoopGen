#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *temp = malloc(K * sizeof(uint64_t));
    for (i = 0; i < K; i++) {
        temp[i] = i * i + 1;
        for (j = i + 1; j < K; j++) {
            temp[j] += temp[i]; // Introduces RAW dependency: temp[j] depends on previous temp[i]
        }
    }
    free(temp);
}
