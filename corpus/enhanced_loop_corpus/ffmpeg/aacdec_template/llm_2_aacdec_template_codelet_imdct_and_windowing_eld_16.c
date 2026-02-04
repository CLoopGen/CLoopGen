#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i += 2) {
        arr[i] = i; // Strided write access with step 2
    }
    free(arr);
}
