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
    for (i = streams_pos + 1; i < argc - num; i++) {
        int idx = i - streams_pos - 1;
        keys[idx].flags = 0;
        keys[idx].pos = i;
    }
}
