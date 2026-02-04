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
    int stride = 4;
    for (i = 0; i < stats_size; i++) {
        dst[i] = 255;
        uint64_t stat_val = stats[i];
        if ((stat_val & 1) || (stat_val > 100) || !skip0) {
            if (size + 3 < 65535) {
                map[size++] = i;
                map[size++] = (i + stat_val) % stats_size;
                map[size++] = (i + (stat_val >> 8)) % stats_size;
            } else {
                map[size++] = i;
            }
        }
    }
}
