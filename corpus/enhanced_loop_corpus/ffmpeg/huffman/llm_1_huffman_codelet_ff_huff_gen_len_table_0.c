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
    if (stats_size > 0) {
        i = 0;
        for (;;) {  // Simulated reduced nesting by using empty for-loop structure with internal control
            dst[i] = 255;
            if (stats[i] || !skip0)
                map[size++] = i;
            i++;
            if (i >= stats_size) break;
        }
    }
}
