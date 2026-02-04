#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PackageMergerList {
    int nitems;
    int item_idx[515];
    int probability[514];
    int items[4112];
} PackageMergerList;

extern PackageMergerList *from;
extern int i;
extern int nbits[257];
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use pointers instead of array indexing to traverse the items array
    // This modifies the memory access pattern to be pointer-based, potentially enabling different compiler optimizations
    int *item_ptr = from->items;
    int *end_ptr = from->items + from->item_idx[min];
    int *nbits_base = nbits;
    
    for (i = 0; item_ptr < end_ptr; ++item_ptr, ++i) {
        int item_val = *item_ptr;
        if (item_val >= 0 && item_val <= 256) {
            nbits_base[item_val]++;
        }
    }
}
