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
    int64_t *array = (int64_t*)calloc(size2, sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            array[j] = i + j; // Remove loop-carried dependency by making access independent across i
        }
    }
    free(array);
}
