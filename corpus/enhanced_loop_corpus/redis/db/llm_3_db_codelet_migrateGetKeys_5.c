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
    // Variant 2: Reverse consecutive memory access
    int j;
    for (j = num - 1; j >= 0; j--) {
        keys[j].pos = first + j;
        keys[j].flags = (1ULL << 1) | (1ULL << 4) | (1ULL << 7);
    }
}
