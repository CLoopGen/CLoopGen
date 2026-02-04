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
    for (i = 0; i < 256; i++) {
        int64_t prev_prob = (i == 0) ? 0 : counts[i-1].prob;
        counts[i].prob = prev_prob + 1;
        counts[i].value = 255 - i;
    }
}
