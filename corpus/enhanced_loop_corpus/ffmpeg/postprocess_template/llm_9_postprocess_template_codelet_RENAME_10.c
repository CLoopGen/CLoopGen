#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int ref = x * y + 3;
        int cur = (x + y) * 2 - 1;
        int d1 = ref - cur;
        int d2 = ref + cur;
        d += (d1 * d1) + (d2 * d2) + d1 * d2;
    }
}
}
