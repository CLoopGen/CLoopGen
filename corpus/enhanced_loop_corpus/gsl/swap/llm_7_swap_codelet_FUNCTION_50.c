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
    uint64_t *array = (uint64_t*)calloc(size1, sizeof(uint64_t));
    if (!array) return; // Handle allocation failure

    for (i = 0; i < size1; i++) {
        array[i] = i * 2; // Write to array element (WAW possible if reordered)
        for (j = i + 1; j < size2; j++) {
            array[i] += j; // RAW: j used to update array[i]; loop-carried dependence on array[i]
        }
    }

    free(array);
}
