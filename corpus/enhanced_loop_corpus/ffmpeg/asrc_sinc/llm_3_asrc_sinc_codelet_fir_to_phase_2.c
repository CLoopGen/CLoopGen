#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *len;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(work_len * sizeof(int));
    for (i = 0; i < work_len; i += 4) { // Strided access with stride of 4
        array[i] = i * i;
    }
    free(array);
}
