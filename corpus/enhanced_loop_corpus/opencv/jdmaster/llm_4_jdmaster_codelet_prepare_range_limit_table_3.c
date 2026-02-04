#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 128; i < 2 * (255 + 1); i++) {
        if (i >= 256) continue;
        table[i] = 255;
    }
}
