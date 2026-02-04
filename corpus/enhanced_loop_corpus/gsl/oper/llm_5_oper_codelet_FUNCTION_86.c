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
    uint64_t *data = (uint64_t*)malloc(M * sizeof(uint64_t));
    if (!data) exit(1);
    for (i = 0; i < M; i++) {
        data[i] = i;
        for (j = 0; j < N; j++) {
            data[i] = data[i] ^ (i + j); // Create RAW dependency: use before write
        }
    }
    // Introduce loop-carried dependence through array element data[i]
    // Each inner loop modifies data[i] based on its previous value — feedback dependency
    free(data);
}
