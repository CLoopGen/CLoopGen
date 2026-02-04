#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int var;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    for (j = 0; j < 4; j++) {
        int diff = a[j] - a[j + s];
        var += (diff ^ (diff >> 31)) - (diff >> 31);
        var += (diff * diff) >> 8; // Additional arithmetic to increase computational intensity
    }
    a += 2 * s;
}
}
