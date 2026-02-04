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
    // Variant 1: Strided memory access pattern
    // Instead of accessing items sequentially, access every 2nd element in a strided manner
    // This changes spatial locality and may affect cache behavior.
    int stride = 2;
    int limit = from->item_idx[min];
    for (i = 0; i < limit; i += stride) {
        if (from->items[i] >= 0 && from->items[i] <= 256) {
            nbits[from->items[i]]++;
        }
    }
    // Handle remaining element if limit is odd
    if (limit % 2 == 1) {
        i = limit - 1;
        if (from->items[i] >= 0 && from->items[i] <= 256) {
            nbits[from->items[i]]++;
        }
    }
}
