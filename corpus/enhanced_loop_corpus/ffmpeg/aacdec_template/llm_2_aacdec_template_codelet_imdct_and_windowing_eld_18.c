#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n2; i++) {
        array[i] = i; // Consecutive memory access: writing in sequential order
    }
    free(array);
}
