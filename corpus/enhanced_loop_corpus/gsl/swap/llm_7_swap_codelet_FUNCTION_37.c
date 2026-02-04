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
    int64_t *array = (int64_t*)malloc(size1 * sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < size1; i++) {
        array[i] = i * 2;
        for (j = i + 1; j < size2; j++) {
            array[i] += j - i;
        }
    }
    free(array);
}
