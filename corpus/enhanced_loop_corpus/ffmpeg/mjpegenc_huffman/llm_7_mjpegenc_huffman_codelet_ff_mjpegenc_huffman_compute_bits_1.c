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



void loop(){
    int local_min = min;
    int limit = from->item_idx[local_min];
    int *items_ptr = from->items;
    for (i = 0; i < limit; i++) {
        int idx = items_ptr[i];
        if (idx >= 0 && idx < 257) {
            nbits[idx] += 1;
        }
    }
}
