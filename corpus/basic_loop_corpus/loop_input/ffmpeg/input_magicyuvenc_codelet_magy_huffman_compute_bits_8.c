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

PackageMergerList *from;
int i;
int nbits[257];
int min;

void init_vars() {
    from = (PackageMergerList*)calloc(1, sizeof(PackageMergerList));
    if (!from) exit(1);

    min = 10; // ensure min is within valid range for item_idx indexing

    from->nitems = 4112;
    for (int j = 0; j < 515; j++) {
        from->item_idx[j] = (j <= min) ? 0 : 4112;
    }
    from->item_idx[min] = 4112; // set the actual bound used in loop

    // Fill items with valid indices in range [0, 256] to match nbits size
    for (int j = 0; j < 4112; j++) {
        from->items[j] = rand() % 257;
    }

    // Initialize nbits array to zero
    for (int j = 0; j < 257; j++) {
        nbits[j] = 0;
    }

    i = 0;
}