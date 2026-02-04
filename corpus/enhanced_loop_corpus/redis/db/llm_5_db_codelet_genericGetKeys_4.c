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
    for (i = 0; i < num; i++) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = (i > num / 2) ? 1 : 0;
    }
}
