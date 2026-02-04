#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using pointer arithmetic
    JSAMPLE *ptr = table + 128;
    int limit = 2 * (255 + 1) - 128;
    for (i = 0; i < limit; i++) {
        ptr[i] = 255;
    }
}
