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
        if (i + 1 < n) {
            arr[i] = i;       // Consecutive-like access pattern by touching adjacent elements
            arr[i + 1] = i+1;
        }
    }
    free(arr);
}
