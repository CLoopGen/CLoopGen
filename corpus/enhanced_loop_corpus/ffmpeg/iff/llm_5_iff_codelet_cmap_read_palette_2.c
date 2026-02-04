#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i++) {
        pal[i] = (i % 2 == 0) ? (pal[i] & 16777215) : pal[i];
    }
}
