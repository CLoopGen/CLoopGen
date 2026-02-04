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
    if (!data) return;

    for (i = 0; i < M; i++) {
        data[i] = i * i; // Write without dependency on previous writes (WAW removed by using unique index)
        for (j = 0; j < N; j++) {
            data[i] += j; // RAW: 'j' used to update data[i]; no loop-carried dep across i-iterations due to per-i storage
        }
    }

    free(data);
}
