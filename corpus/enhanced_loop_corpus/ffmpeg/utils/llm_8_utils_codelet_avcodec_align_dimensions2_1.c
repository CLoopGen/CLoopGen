#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize_align[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        linesize_align[i % 4] = 8 + i;
        linesize_align[(i + 1) % 4] = 8 - i;
    }
}
