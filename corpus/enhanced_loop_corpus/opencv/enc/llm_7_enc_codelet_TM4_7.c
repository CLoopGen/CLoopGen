#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[4];
for (y = 0; y < 4; ++y) {
    const int *const clip_table = temp;
    temp[y] = y * 2;
    for (x = 0; x < 4; ++x) {
        if (x > 0) {
            temp[x] += temp[x-1];
        }
    }
}
}
