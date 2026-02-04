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
    size_t *array = (size_t*)calloc(N, sizeof(size_t));
    if (!array) return; // Handle allocation failure

    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            array[j] = array[i] + 1; // Introduce loop-carried RAW and WAR dependency via array
        }
    }

    free(array);
}
