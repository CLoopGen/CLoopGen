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
        if (i % 2 == 0) {
            keys[i].pos = firstKeyOfs + (i * keyStep);
            keys[i].flags = 0;
        } else {
            keys[i].pos = firstKeyOfs;
            keys[i].flags = 1;
        }
    }
}
