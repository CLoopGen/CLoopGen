#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *len;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(*len * sizeof(int));
    for (i = 0; i < *len; i++) {
        array[i] = i * 4; // Consecutive write access
    }
    free(array);
}
