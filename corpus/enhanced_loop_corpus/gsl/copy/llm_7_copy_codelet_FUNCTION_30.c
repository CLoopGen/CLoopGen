#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *array = (uint64_t*)malloc(sizeof(uint64_t) * ((M) < (N) ? (M) : (N)));
    if (!array) return;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        array[i] = i * 2;
        if (i > 0) {
            array[i] += array[i - 1]; // Introduce loop-carried RAW dependency: each iteration depends on previous result
        }
    }
    // This variant introduces a true data dependency (RAW) across iterations via array elements,
    // creating a sequential update pattern (e.g., prefix-like computation).
    // Also includes WAW on each array[i], but only one write per element.
    free(array);
}
