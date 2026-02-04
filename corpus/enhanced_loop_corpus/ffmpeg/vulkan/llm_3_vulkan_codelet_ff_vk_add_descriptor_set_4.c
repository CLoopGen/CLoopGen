#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 2
    int *arr = (int*)malloc(num * 2 * sizeof(int));  // Allocate extra space for strided access
    for (int i = 0; i < num; i++) {
        arr[i * 2] = i;  // Access every second element (strided access)
    }
    free(arr);
}
