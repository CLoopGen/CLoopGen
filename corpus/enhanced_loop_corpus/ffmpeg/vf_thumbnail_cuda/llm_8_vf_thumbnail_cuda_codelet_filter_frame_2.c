#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 256; i < (4 * 256); i += 2) {
        hist[i] = 4 * hist[i] + 2 * hist[i];
    }
}
