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
    int64_t* arr = (int64_t*)calloc(N, sizeof(int64_t));
    if (!arr) return;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Introduce RAW: each write to arr[j] is independent across i, but carried across j
            // No WAR/WAW due to unique index access per j
            arr[j] = (i % 2 == 0) ? (arr[j] + i + 1) : (arr[j] - j);
        }
    }
    free(arr);
}
