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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < num; i += 2) {
        keys[i].pos = first + i;
        keys[i].flags = (1ULL << 1) | (1ULL << 4) | (1ULL << 7);
    }
    // Handle odd-sized num if needed by processing last element
    if (num % 2 == 1) {
        keys[num - 1].pos = first + num - 1;
        keys[num - 1].flags = (1ULL << 1) | (1ULL << 4) | (1ULL << 7);
    }
}
