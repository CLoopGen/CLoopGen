#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ret;
extern int i;
extern short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    short prev_val = 0;
    for (i = 0; i < ret; i += 4) {
        short curr = *p;
        *p = ~prev_val;
        prev_val = curr;
        p += 2;
    }
}
