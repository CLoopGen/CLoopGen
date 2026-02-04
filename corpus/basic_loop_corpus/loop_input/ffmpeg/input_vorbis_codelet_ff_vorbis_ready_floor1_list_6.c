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

vorbis_floor1_entry *list;
int values;
int i;

void init_vars() {
    values = 65536; 
    list = (vorbis_floor1_entry*)calloc(values, sizeof(vorbis_floor1_entry));
    if (!list) {
        exit(1);
    }

    for (int idx = 0; idx < values; idx++) {
        list[idx].x = (uint16_t)(idx * 7891 % 65432); 
        list[idx].sort = 0;
        list[idx].low = 0;
        list[idx].high = 0;
    }

    i = 0;
}