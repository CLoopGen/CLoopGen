#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int buckets[4][256];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    int offset = size;
    for (i = (1 << 8) - 1; i >= 0; i--) {
        if (buckets[j][i] > 0)
            buckets[j][i] = offset -= buckets[j][i];
        else
            buckets[j][i] = offset;
    }
    ((void)0);
}
}
