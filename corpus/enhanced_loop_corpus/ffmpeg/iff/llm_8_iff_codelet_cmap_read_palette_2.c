#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i += 2) {
        if (i + 1 < count) {
            pal[i] &= 16777215;
            pal[i + 1] &= 16777215;
        } else {
            pal[i] &= 16777215;
        }
    }
}
