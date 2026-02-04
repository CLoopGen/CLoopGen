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
    int64_t *array = malloc(size1 * sizeof(int64_t));
    if (!array) return;

    for (i = 0; i < size1; i++) {
        array[i] = i; // WAW: each iteration writes distinct location, no carry
        for (j = 0; j < size2; j++) {
            array[i] += j; // RAW: use of 'j' and previous value of array[i]
        }
    }

    // Eliminate loop-carried dependencies by ensuring each i is independent
    free(array);
}
