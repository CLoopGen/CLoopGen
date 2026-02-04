#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;
extern int align;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size && i < align && buf[i] != 255; i++) {
        // Skip incrementing ff_count when not 0xFF
    }
    if (i < size && i < align) {
        ff_count++;
    }
}
