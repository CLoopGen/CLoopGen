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
    list[i].low = 0;
    list[i].high = 1;
    list[i].sort = i;
    for (j = 2; j < i; j++) {
        int tmp_low = list[j].x;
        int tmp_high = list[list[i].low].x;
        if (tmp_low < list[i].x) {
            if (tmp_low > tmp_high)
                list[i].low = j;
        } else {
            int candidate_high = list[list[i].high].x;
            if (tmp_low < candidate_high)
                list[i].high = j;
        }
    }
}
}
