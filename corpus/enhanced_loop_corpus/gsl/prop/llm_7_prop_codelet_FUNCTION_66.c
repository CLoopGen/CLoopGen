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
    int64_t *array = (int64_t*)malloc(size1 * sizeof(int64_t));
    if (!array) return;

    for (i = 0; i < size1; i++) {
        array[i] = i; // WAW: multiple writes to array[i] across iterations (though no prior read)
        for (j = 0; j < size2; j++) {
            array[i] += j; // RAW: read-modify-write introduces dependency on previous value
        }
    }

    // Eliminate loop-carried dependencies by making inner loop independent per i
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            array[i] ^= i ^ j; // Independent operation, but accumulates in array[i]
        }
    }

    free(array);
}
