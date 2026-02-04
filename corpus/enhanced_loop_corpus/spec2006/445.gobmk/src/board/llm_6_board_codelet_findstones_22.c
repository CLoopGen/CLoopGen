#include <stdio.h>

#include <inttypes.h>

extern int next_stone[400];
extern int maxstones;
extern int *stones;
extern int size;
extern int pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_pos = pos;
    for (k = 0; k < maxstones && k < size; k++) {
        stones[k] = temp_pos;
        temp_pos = next_stone[temp_pos];
    }
}
