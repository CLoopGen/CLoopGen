#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int pos;
    int flags;
} keyReference;

extern int i;
extern int num;
extern int first;
extern keyReference *keys;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num; i++) {
    keys[i].pos = first + i;
    if (i >= 5) {
        keys[i].flags = (1ULL << 1) | (1ULL << 4) | (1ULL << 7);
    } else {
        keys[i].flags = (1ULL << 4);
    }
}
}
