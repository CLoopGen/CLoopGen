#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = 0;
    for (i = 0; i < count; i++) {
        uint32_t current = pal[i];
        pal[i] = (current & 16777215) ^ prev;
        prev = current & 16777215;
    }
}
