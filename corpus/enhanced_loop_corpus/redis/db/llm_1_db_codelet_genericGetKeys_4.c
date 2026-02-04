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
    // Variant 2: Reduced loop nesting by inlining what could have been a separate initialization loop
    // This version eliminates any potential nested structure by using a single flat loop
    i = 0;
    for (; i < num; i++) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
    }
}
