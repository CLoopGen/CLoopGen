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
    int64_t *array = (int64_t*)malloc(M * sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        array[i] = i;
        for (j = 0; j < N; j++) {
            array[i] += j;
        }
    }
    // Introduce WAR (write-after-read) and WAW dependencies through array[i].
    // Loop-carried dependence is removed across iterations of i, but carried within inner loop via array[i] update.
    free(array);
}
