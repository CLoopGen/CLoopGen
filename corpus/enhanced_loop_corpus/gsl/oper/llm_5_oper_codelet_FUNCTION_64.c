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
    int64_t *data = (int64_t*)malloc(N * sizeof(int64_t));
    if (!data) return;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Remove loop-carried dependency by making each iteration independent
            data[j] = (i + 1) * (j + 1); // RAW: use of i,j; no WAR/WAW across iterations
        }
    }

    free(data);
}
