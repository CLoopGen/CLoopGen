#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint64_t *stats;
extern int stats_size;
extern int skip0;
extern uint16_t *map;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < stats_size; i++) {
    dst[i] = 255;
    if (skip0 && !stats[i])
        continue;
    map[size++] = i;
}
}
