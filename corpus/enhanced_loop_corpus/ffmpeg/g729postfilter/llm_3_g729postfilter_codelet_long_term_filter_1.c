#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic
    // Instead of indexing with 'i', use a pointer that walks through the array
    int limit = subframe_size + (143 + 8 + 1);
    int16_t *ptr = residual;
    for (i = 0; i < limit; i++) {
        tmp |= ((*ptr) >= 0 ? (*ptr) : (-(*ptr)));
        ptr++;
    }
}
