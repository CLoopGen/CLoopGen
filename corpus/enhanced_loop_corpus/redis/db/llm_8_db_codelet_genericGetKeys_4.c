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
    int limit = num + (num >> 1); // Increase trip count by 50%
    for (i = 0; i < limit; i++) {
        int adjusted_i = i % num;
        keys[adjusted_i].pos += firstKeyOfs + (adjusted_i * keyStep); // Additional arithmetic: compound assignment and multiplication
        keys[adjusted_i].flags = (keys[adjusted_i].flags ^ 1) & 1; // More complex flag setting using XOR
    }
}
