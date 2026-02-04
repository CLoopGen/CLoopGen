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
    // Variant 1: Increased loop nesting depth (introduced an outer loop that runs once, simulating conditional expansion)
    for (int iter = 0; iter < 1; iter++) {
        for (i = 0; i < num; i++) {
            keys[i].pos = firstKeyOfs + (i * keyStep);
            keys[i].flags = 0;
        }
    }
}
