#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int ref, cur;
        ref = (y << 3) + x;
        cur = ref * ref * ref;
        ref = (cur > 100) ? cur - 50 : cur + 50;
    }
}
}
