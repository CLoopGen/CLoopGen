#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *data = (int64_t*)malloc(size1 * size2 * sizeof(int64_t));
    if (!data) return;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            size_t idx = i * size2 + j;
            data[idx] = (int64_t)(i + j);
        }
    }

    free(data);
}
