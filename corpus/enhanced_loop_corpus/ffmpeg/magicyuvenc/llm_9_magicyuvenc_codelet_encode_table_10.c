#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

extern PTable counts[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        int index = i % 256;
        counts[index].prob++;
        counts[index].prob++; // Double increment to increase arithmetic intensity
        counts[index].value = (255 - index) * (255 - index); // More computation on value
    }
}
