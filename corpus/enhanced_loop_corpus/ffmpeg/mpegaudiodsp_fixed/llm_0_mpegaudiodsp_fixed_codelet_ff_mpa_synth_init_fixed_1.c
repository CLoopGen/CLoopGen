#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int row = i / 16;
    int col = i % 16;
    if (row < 8)
        window[512 + 16 * row + col] = window[64 * row + 32 - col];
}
}
