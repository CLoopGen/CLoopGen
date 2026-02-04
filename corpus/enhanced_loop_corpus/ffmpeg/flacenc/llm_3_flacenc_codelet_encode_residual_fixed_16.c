#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from the end to the beginning, maintaining unit stride but reversing access pattern
    for (i = order - 1; i >= 0; i--) {
        res[i] = smp[i];
    }
}
