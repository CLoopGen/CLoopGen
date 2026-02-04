#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i += 2) { // Strided access with step size 2
        if (i < num) {
            arr[i] = i;
        }
    }
    free(arr);
}
