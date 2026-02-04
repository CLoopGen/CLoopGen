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
for (k = 0; k < maxstones && k < size; k++) {
    stones[k] = pos;
    if (next_stone[pos] == -1) {
        pos = -1;
    } else {
        pos = next_stone[pos];
    }
}
}
