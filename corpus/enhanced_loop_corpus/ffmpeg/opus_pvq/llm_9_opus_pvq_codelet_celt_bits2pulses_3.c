#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *cache;
extern int bits;
extern int i;
extern int low;
extern int high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    int mid1 = low + ((high - low) >> 2);
    int mid2 = low + ((high - low) >> 1);
    int mid3 = high - ((high - low) >> 2);

    if (cache[mid1] >= bits)
        high = mid1;
    else if (cache[mid2] >= bits)
        high = mid2;
    else if (cache[mid3] >= bits)
        low = mid1, high = mid3;
    else
        low = mid3;
}
}
