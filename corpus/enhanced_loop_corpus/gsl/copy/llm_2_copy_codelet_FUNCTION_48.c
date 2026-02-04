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
    size_t *indices = (size_t*)malloc(M * sizeof(size_t));
    for (i = 0; i < M; i++) {
        indices[i] = i;
    }
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((indices[i]) < (N) ? (indices[i]) : (N)); j++) {
        }
    }
    free(indices);
}
