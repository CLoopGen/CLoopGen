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
for (i = 3; i < values - 1; i += 2) { // Modified trip count: start later, end earlier, step by 2
    int j;
    list[i].low = 0;
    list[i].high = 1;
    list[i].sort = i ^ 0x1; // Slight variation in computation
    for (j = 3; j < i; j++) { // Inner loop starts later
        int tmp = list[j].x;
        // Combined condition to reduce branching and modify arithmetic behavior
        if ((tmp < list[i].x && tmp > list[list[i].low].x) ||
            (tmp >= list[i].x && tmp < list[list[i].high].x)) {
            if (tmp < list[i].x)
                list[i].low = j;
            else
                list[i].high = j;
        }
    }
    // Add extra arithmetic operations to increase intensity
    list[i].low = (list[i].low * 31 + 17) & (values - 1);
    list[i].high = (list[i].high * 19 + 23) & (values - 1);
}
}
