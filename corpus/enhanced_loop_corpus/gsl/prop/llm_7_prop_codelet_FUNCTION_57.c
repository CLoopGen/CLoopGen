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
    int64_t* array = (int64_t*)malloc(size2 * sizeof(int64_t));
    if (!array) return;

    for (i = 0; i < size1; i++) {
        // Eliminate loop-carried dependencies: each iteration independent
        for (j = 0; j < size2; j++) {
            array[j] = (i + 1) * (j + 1); // WAW hazard avoided by per-iteration independence
        }
    }

    free(array);
}
