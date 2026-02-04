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
    int i;
    for (i = 0, k = 0; k < maxstones && k < size; k++, i++) {
        stones[i] = pos;
        if (k + 1 < maxstones && k + 1 < size) {
            stones[i + 1] = next_stone[pos];
        }
        pos = next_stone[next_stone[pos]];
        k++;
    }
    if ((maxstones & 1) == 0 && (size & 1) == 0) k--;
}
