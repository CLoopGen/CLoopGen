#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *data = malloc(K * sizeof(uint64_t));
    for (i = 0; i < K; i++) {
        data[i] = 0;
    }
    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j++) {
            data[i] += j; // Creates WAW and WAR dependencies on data[i], but no loop-carried dependency across outer iterations
        }
    }
    free(data);
}
