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
    int temp_pos[num];
    int temp_flags[num];
    for (i = 0; i < num; i++) {
        temp_pos[i] = firstKeyOfs + (i * keyStep);
        temp_flags[i] = 0;
    }
    for (i = 0; i < num; i++) {
        keys[i].pos = temp_pos[i];
        keys[i].flags = temp_flags[i];
    }
}
