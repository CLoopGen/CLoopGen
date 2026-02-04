#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int in;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size * size * size >= in) return;
    for (size = 1; ; ) {
        size++;
        if (size * size * size >= in) break;
    }
}
