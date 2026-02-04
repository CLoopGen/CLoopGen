#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect indexing via pointer arithmetic
    // Use pointers incremented by fixed strides to simulate even-index access
    IDWTELEM *bp = b + 2;
    IDWTELEM *tp = temp + 2;
    IDWTELEM *tp_end = temp + width - 1;

    for (; tp < tp_end; bp += 2, tp += 2) {
        *(bp) = *tp - (((*(tp - 1) + *(tp + 1) + 2)) >> 2);
        *(bp - 1) = *(tp - 1) + (((*(bp - 2) + *bp + 1)) >> 1);
    }
}
