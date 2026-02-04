#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(width * sizeof(int));
    for (i = 0; i < width; ++i) {
        array[i] = i; // Consecutive memory access: writing to adjacent elements
    }
    free(array);
}
