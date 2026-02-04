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
    int j, k;
    list[i].low = 0;
    list[i].high = 1;
    list[i].sort = i;
    for (j = 2; j < i; j++) {
        for (k = j; k < j + 1; k++) { // Artificially increased nesting depth with logically equivalent inner loop
            int tmp = list[k].x;
            if (tmp < list[i].x) {
                if (tmp > list[list[i].low].x)
                    list[i].low = k;
            } else {
                if (tmp < list[list[i].high].x)
                    list[i].high = k;
            }
        }
    }
}
}
