#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 4; j++) {
        for (i = 256; i < (3 * 256); i++)
            hist[i] = 4 * hist[i];
    }
}
