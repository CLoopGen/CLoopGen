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



void loop() {
    // Variant 1: Modified memory access pattern using strided access (stride of 2) on the inner loop
    for (i = 2; i < values; i += 1) {
        int j;
        list[i].low = 0;
        list[i].high = 1;
        list[i].sort = i;
        // Strided forward traversal with step size 2, covering even indices first
        for (j = 2; j < i; j += 2) {
            int tmp = list[j].x;
            if (tmp < list[i].x) {
                if (tmp > list[list[i].low].x)
                    list[i].low = j;
            } else {
                if (tmp < list[list[i].high].x)
                    list[i].high = j;
            }
        }
        // Handle odd indices in a second pass to maintain coverage
        for (j = 3; j < i; j += 2) {
            int tmp = list[j].x;
            if (tmp < list[i].x) {
                if (tmp > list[list[i].low].x)
                    list[i].low = j;
            } else {
                if (tmp < list[list[i].high].x)
                    list[i].high = j;
            }
        }
    }
}
