#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t* arr = (int64_t*)malloc(size1 * sizeof(int64_t));
    if (!arr) return;
    for (i = 0; i < size1; i++) {
        arr[i] = i * 2;
        for (j = 0; j < size2; j++) {
            arr[i] += j; // Read after write (RAW) dependency: each iteration reads arr[i] written in same outer loop
        }
    }
    // Eliminate loop-carried dependency across outer iterations by confining writes to arr[i]
    free(arr);
}
