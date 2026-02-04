#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(width * 2 * sizeof(int));
    for (i = 0; i < width; ++i) {
        array[i * 2] = i; // Strided memory access: writing every second element (stride of 2)
    }
    free(array);
}
