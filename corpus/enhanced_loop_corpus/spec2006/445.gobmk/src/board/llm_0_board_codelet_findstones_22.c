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
int k1;
for (k1 = 0; k1 < maxstones && k1 < size; k1++) {
    for (k = k1; k < k1 + 1; k++) {
        stones[k] = pos;
        pos = next_stone[pos];
    }
}
}
