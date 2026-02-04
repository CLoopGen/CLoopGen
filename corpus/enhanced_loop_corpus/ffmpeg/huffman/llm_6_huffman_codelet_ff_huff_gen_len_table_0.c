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
    uint16_t temp_val;
    for (i = 0; i < stats_size; i++) {
        dst[i] = 255;
        temp_val = size; // Introduce temporary to create WAW dependency on size
        if (stats[i] || !skip0) {
            map[temp_val] = i;
            size = temp_val + 1; // Update size only after use
        }
    }
}
