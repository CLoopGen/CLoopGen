#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int pos;
    int flags;
} keyReference;

extern int argc;
extern int i;
extern int num;
extern keyReference *keys;
extern int streams_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset pre-computation
    int start = streams_pos + 1;
    int end = argc - num;
    int base_index = -streams_pos - 1;
    for (i = start; i < end; i++) {
        int idx = i + base_index;
        keys[idx].pos = i;
        keys[idx].flags = 0;
    }
}
