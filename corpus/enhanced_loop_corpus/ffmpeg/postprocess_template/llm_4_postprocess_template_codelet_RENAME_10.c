#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int ref[64];
int cur[64];
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int index = y * 8 + x;
        int d1 = ref[index] - cur[index];
        d += d1 * d1;
    }
}
}
