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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < num; i++) {
            keys[i].pos = first + i;
            keys[i].flags = (1ULL << 1) | (1ULL << 4) | (1ULL << 7);
        }
    }
}
