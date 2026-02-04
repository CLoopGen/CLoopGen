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
    int offset;
    for (i = streams_pos + 1; i < argc - num; i++) {
        offset = i - streams_pos - 1;
        if (offset >= 0 && keys != NULL) {
            keys[offset].pos = i;
            keys[offset].flags = 0;
        } else {
            break;
        }
    }
}
