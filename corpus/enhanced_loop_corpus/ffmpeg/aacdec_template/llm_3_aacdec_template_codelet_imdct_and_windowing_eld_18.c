#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(n2 * sizeof(int));
    int stride = 2;
    for (i = 0; i < n2; i += stride) {
        if (i < n2) {
            array[i] = i; // Strided memory access: accessing every second element
        }
    }
    free(array);
}
