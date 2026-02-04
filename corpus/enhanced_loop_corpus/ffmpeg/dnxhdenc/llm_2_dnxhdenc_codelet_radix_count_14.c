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
    for (i = 0; i < 256; i++)
        buckets[j][i] = offset -= buckets[j][255 - i];
    ((void)0);
}
}
