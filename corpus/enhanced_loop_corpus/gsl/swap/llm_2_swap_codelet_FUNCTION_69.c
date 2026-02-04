#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *array = (size_t*)malloc(size1 * sizeof(size_t));
    for (p = 0; p < size1; p += 2) {
        size_t k = array[p];
        size_t n = array[p + 1]; 
    }
    free(array);
}
