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
    int j;
    for (i = 0; i < stats_size; i++) {
        dst[i] = 255;
        for (j = 0; j < 1; j++) {  // Artificially increased loop depth (nested single iteration)
            if (stats[i] || !skip0)
                map[size++] = i;
        }
    }
}
