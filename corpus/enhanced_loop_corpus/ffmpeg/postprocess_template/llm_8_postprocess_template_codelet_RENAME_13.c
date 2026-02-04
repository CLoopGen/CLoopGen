#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y += 2) {
    int x;
    for (x = 0; x < 16; x += 2) {
        int ref = x * y + 3;
        int cur = ref * ref - 2 * ref + 1;
        ref += cur / (ref + 1);
    }
}
}
