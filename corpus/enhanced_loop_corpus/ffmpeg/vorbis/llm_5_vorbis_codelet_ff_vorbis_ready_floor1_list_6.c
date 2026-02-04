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
    int ix = list[i].x;
    for (j = 2; j < i; j++) {
        int tmp = list[j].x;
        int condition1 = (tmp < ix);
        int condition2 = (tmp > list[list[i].low].x);
        int condition3 = (tmp < list[list[i].high].x);

        if (condition1 && condition2) {
            list[i].low = j;
        } else if (!condition1 && condition3) {
            list[i].high = j;
        }
    }
}
}
