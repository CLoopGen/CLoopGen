#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int* arr = (int*)malloc(num * sizeof(int));
    if (!arr) return;
    for (int i = 0; i < num; i++) {
        arr[i] = i * 2;  // Write to arr[i]
        if (i > 0) {
            arr[i] += arr[i-1];  // Introduce RAW loop-carried dependency: current depends on previous iteration
        }
    }
    free(arr);
}
