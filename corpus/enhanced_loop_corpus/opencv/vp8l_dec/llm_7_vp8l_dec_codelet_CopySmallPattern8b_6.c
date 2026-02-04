#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_array[4];
    for (i = 0; i < (length >> 2); ++i) {
        local_array[i & 3] = i + 1;
        local_array[(i + 1) & 3] = local_array[i & 3] * 2;
    }
    // Introduces WAR and RAW dependencies through indexed writes/reads to 'local_array'.
    // Loop-carried dependency due to potential overwriting of array elements across iterations.
}
