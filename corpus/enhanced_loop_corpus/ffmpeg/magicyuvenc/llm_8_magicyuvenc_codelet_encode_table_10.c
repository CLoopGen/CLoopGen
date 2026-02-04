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
    for (i = 0; i < 256; i += 2) {
        counts[i].prob += 2;
        counts[i].value = 255 - i;
        if (i + 1 < 256) {
            counts[i + 1].prob += 2;
            counts[i + 1].value = 255 - (i + 1);
        }
    }
}
