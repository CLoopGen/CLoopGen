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
int offset;
for (j = 0; j < 4; j++) {
    offset = size;
    i = (1 << 8) - 1;
    for (; i >= 0; i--) {
        buckets[j][i] = offset -= buckets[j][i];
    }
    ((void)0);
}
}
