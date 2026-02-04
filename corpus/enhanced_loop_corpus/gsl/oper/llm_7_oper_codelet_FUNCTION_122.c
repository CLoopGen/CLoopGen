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
    volatile size_t *data = (volatile size_t*)malloc(M * sizeof(size_t));
    if (!data) return;

    for (i = 0; i < M; i++) {
        data[i] = i;
        for (j = 0; j < N; j++) {
            data[i] += (j & 1) ? 1 : -1;
            // RAW dependency: j used to compute update to data[i]
            // Loop-carried WAW dependency on data[i] across inner iterations
            // No cross-iteration dependency in i-loop due to independent indices
        }
    }
    free((void*)data);
}
