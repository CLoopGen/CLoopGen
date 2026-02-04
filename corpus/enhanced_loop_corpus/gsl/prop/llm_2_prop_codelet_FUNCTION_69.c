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
    size_t *indices = (size_t*)malloc(size2 * sizeof(size_t));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            indices[j] = j;
        }
        for (j = 0; j < size2; j += 2) {
            if (j + 1 < size2) {
                size_t temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    free(indices);
}
