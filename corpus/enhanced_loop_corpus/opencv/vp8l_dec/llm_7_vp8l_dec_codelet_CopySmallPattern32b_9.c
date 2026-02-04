#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc((length >> 1) * sizeof(int));
    if (!array) return;
    for (i = 0; i < (length >> 1); ++i) {
        array[i] = i;
        array[i-1] = array[i] + 1; // WAR hazard introduced when i > 0
    }
    // Introduces WAR and RAW dependencies through memory accesses
    // Loop-carried dependence due to potential overlap in memory writes
    free(array);
}
