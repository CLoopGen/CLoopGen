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
    int prev_val, curr_val;
    prev_val = buckets[j][(1 << 8) - 1];
    buckets[j][(1 << 8) - 1] = offset - prev_val;
    offset = buckets[j][(1 << 8) - 1];
    for (i = (1 << 8) - 2; i >= 0; i--) {
        curr_val = buckets[j][i];
        buckets[j][i] = offset - curr_val;
        offset = buckets[j][i];
    }
    ((void)0);
}
}
