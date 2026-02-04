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
    int start = streams_pos + 1;
    int end = argc - num;
    for (i = start; i < end; i += 2) {
        int idx = i - streams_pos - 1;
        keys[idx].pos = i;
        keys[idx].flags = 0;
        if (i + 1 < end) {
            int next_idx = i + 1 - streams_pos - 1;
            keys[next_idx].pos = i + 1;
            keys[next_idx].flags = 0;
        }
    }
}
