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
    int64_t *data = (int64_t*)calloc(N, sizeof(int64_t));
    if (!data) return;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            data[j] = data[i] + j; // Introduce RAW and WAW dependency on data[j]
        }
    }
    free(data);
}
