#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct vorbis_floor1_entry {
    uint16_t x;
    uint16_t sort;
    uint16_t low;
    uint16_t high;
} vorbis_floor1_entry;

extern vorbis_floor1_entry *list;
extern int values;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < values; i++) {
    int j;
    list[i].sort = i;
    list[i].low = i;  // Introduce WAW-like dependency by writing before potential read in next iterations
    list[i].high = i;
    for (j = 2; j < i; j++) {
        int tmp = list[j].x;
        int current_x = list[i].x;
        if (tmp < current_x) {
            if (list[list[i].low].x < tmp) {
                list[i].low = j;  // Update low only when strictly better
            }
        } else if (tmp > current_x) {
            if (list[list[i].high].x > tmp) {
                list[i].high = j;  // Update high only when strictly better
            }
        }
        // Eliminate redundant updates by ensuring both branches don't write to same location
        // Introduces more regular data flow and reduces false dependencies
    }
    // Ensure low and high are within valid range post-processing
    if (list[i].low == i) list[i].low = 0;
    if (list[i].high == i) list[i].high = 1;
}
}
