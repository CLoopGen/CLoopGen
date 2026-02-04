#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; ++y) {
    const int *const clip_table = &x + y;
    for (x = 0; x < 4; ++x) {
        x = x + y;
    }
}
}
