#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nlm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* arr = (uint64_t*)malloc(nlm * sizeof(uint64_t));
    if (arr == NULL) return;
    for (i = 0; i < nlm; ++i) {
        if (i == 0) {
            arr[i] = 1;
        } else {
            arr[i] = arr[i-1] + i; // Introduce loop-carried RAW (read-after-write) dependency
        }
    }
    free(arr);
}
