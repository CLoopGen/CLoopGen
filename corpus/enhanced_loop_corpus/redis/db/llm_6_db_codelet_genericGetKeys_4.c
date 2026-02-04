#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int pos;
    int flags;
} keyReference;

extern int firstKeyOfs;
extern int keyStep;
extern int i;
extern int num;
extern keyReference *keys;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = firstKeyOfs;
    for (i = 0; i < num; i++) {
        int stepOffset = i * keyStep;
        keys[i].pos = base + stepOffset;
        keys[i].flags = (i > 0) ? keys[i-1].flags + 1 : 0;
    }
}
