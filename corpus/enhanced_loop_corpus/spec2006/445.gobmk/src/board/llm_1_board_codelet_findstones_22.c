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
for (int outer = 0; outer < 1; outer++) {
    for (k = 0; k < maxstones && k < size; k++) {
        stones[k] = pos;
        pos = next_stone[pos];
    }
}
}
