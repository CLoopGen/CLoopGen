#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k;
for (k = 0; k < 128; k++) {
    i = k / 16;
    j = k % 16;
    window[512 + 16 * i + j] = window[64 * i + 32 - j];
}
}
