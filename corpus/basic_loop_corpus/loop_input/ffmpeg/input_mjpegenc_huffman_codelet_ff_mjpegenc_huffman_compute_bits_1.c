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
    from = (PackageMergerList *)calloc(1, sizeof(PackageMergerList));
    if (!from) exit(1);

    min = 100;
    
    from->nitems = 4112;
    
    for (int j = 0; j < 515; j++) {
        from->item_idx[j] = (j <= min) ? 4112 : 0;
    }
    
    for (int j = 0; j < 514; j++) {
        from->probability[j] = rand() % 100;
    }
    
    for (int j = 0; j < 4112; j++) {
        from->items[j] = rand() % 256;
    }
    
    for (int j = 0; j < 257; j++) {
        nbits[j] = 0;
    }
}