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
    int *local_items = from->items;
    int *local_nbits = nbits;
    int limit = from->item_idx[min];
    int offset = 0;
    for (i = 0; i < limit; i += 4) {
        if (i + 0 < limit) local_nbits[local_items[i + 0]]++;
        if (i + 1 < limit) local_nbits[local_items[i + 1]]++;
        if (i + 2 < limit) local_nbits[local_items[i + 2]]++;
        if (i + 3 < limit) local_nbits[local_items[i + 3]]++;
    }
}
