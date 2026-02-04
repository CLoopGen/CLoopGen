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
for (i = 0; i < 6; i++) {
    for (j = 0; j < 16; j += 2) {
        int diff1 = a[j] - a[j + s];
        int shifted1 = diff1 >> 31;
        int comp1 = (diff1 ^ shifted1) - shifted1;
        var += comp1;

        int diff2 = a[j+1] - a[j + 1 + s];
        int shifted2 = diff2 >> 31;
        int comp2 = (diff2 ^ shifted2) - shifted2;
        var += comp2;
    }
    a += s;
}
}
