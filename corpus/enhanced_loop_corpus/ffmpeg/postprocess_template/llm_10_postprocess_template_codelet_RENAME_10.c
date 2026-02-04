#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int ref = y ^ x;
        int cur = y & x;
        int d1 = ref - cur;
        d += d1 * d1;
        d += d1 * 2;
    }
}
}
