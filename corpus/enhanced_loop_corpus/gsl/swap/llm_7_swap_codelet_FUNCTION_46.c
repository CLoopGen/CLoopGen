#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *array = (size_t*)calloc(K, sizeof(size_t));
    if (!array) return;
    for (i = 0; i < K; i++) {
        array[i] = i;
        for (j = i + 1; j < K; j++) {
            array[j] = array[i] + 1; // Introduces WAW and RAW dependencies
        }
    }
    free(array);
}
