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
    for (i = 0; i < 32; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            counts[idx].prob++;
            counts[idx].value = 255 - idx;
        }
    }
}
