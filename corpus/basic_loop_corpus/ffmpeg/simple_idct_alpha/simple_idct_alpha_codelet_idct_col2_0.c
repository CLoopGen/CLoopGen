#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 8; ++i) {
    int a0 = col[i] + (1 << (20 - 1)) / 16383;
    a0 *= 16383;
    col[i] = a0 >> 20;
}

}
