#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x += 2) {
    for (int j = 0; j < 3; j++) {
        if (x + j >= w2) break;
    }
}
}
