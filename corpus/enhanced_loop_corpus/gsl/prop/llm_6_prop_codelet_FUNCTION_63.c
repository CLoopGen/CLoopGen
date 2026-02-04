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
    int *data = (int*)malloc(size1 * size2 * sizeof(int));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            size_t idx = i * size2 + j;
            data[idx] = (i > 0) ? data[idx - size2] + 1 : 1; // Introduce RAW dependency: each element depends on previous row
        }
    }
    free(data);
}
