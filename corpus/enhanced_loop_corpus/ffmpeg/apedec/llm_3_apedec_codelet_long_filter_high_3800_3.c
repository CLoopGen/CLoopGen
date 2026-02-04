#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer;
extern int order;
extern int i;
extern int32_t delay[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int index_map[256];
    for (i = 0; i < order && i < 256; i++) {
        index_map[i] = order - 1 - i; // Reverse access pattern
    }
    for (i = 0; i < order && i < 256; i++) {
        delay[i] = buffer[index_map[i]];
    }
}
