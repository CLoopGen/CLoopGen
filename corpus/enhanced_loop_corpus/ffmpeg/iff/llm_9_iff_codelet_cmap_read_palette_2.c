#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count * 3; i++) {
        int idx = i % count;
        pal[idx] = (pal[idx] & 16777215) | (pal[idx] >> 24);
    }
}
