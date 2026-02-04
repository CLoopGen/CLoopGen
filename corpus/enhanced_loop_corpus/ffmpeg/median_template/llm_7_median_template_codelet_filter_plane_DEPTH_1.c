#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int* arr = (int*)malloc(width * sizeof(int));
    if (!arr) return;
    for (int i = 0; i < width; i++) {
        arr[i] = i;
        if (i > 0) {
            arr[i] += arr[i-1]; // Introduce loop-carried RAW dependency: each iteration depends on previous result
        }
    }
    free(arr);
}
