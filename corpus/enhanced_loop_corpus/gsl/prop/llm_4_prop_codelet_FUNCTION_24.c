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
    int* temp_array = (int*)malloc(size2 * sizeof(int));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp_array[j] = i + j;
        }
        // Introduce loop-carried dependency: each iteration depends on the previous via temp_array write
        for (j = 1; j < size2; j++) {
            temp_array[j] += temp_array[j-1];
        }
    }
    free(temp_array);
}
