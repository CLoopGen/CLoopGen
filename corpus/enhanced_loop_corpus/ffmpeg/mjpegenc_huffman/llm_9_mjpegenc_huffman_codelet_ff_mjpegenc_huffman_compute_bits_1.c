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
    int factor = (min > 128) ? 1 : 2;
    int limit = from->item_idx[min] * factor;
    for (i = 0; i < limit; i++) {
        int idx = (i % from->item_idx[min]);
        nbits[from->items[idx]] += (i < from->item_idx[min]) ? 1 : 0;
    }
}
