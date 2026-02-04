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
    int step = 3;
    for (i = 0; i < num; i++) {
        keys[i].pos = first + i * step;
        keys[i].flags = (1ULL << (1 + i % 3)) | (1ULL << (4 + i % 2)) | (1ULL << (7 - i % 3));
    }
}
